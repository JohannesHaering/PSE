#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "matrixMult.h"
#include "AOCLUtils/aocl_utils.h"
#include "CL/cl.h"

using namespace aocl_utils;

// Entry point.
int main(int argc, char **argv)
{
  printf("Generating input matrices\n");
  input_a.reset(num_devices);
  output.reset(num_devices);

  std::vector<std::vector<float>> matrixA = std::vector<std::vector<float>>(1024, std::vector<float>(1024));
  for (int y = 0; y < 1024; y++)
  {
    for (int x = 0; x < 1024; x++)
    {
      matrixA[y][x] = y + x;
    }
  }

  std::vector<std::vector<float>> matrixB = std::vector<std::vector<float>>(1024, std::vector<float>(1024));
  for (int y = 0; y < 1024; y++)
  {
    for (int x = 0; x < 1024; x++)
    {
      matrixB[y][x] = y + x;
    } 
  }

  printf("done generating\n");

  multiply(matrixA, matrixB);

  return 0;
}

std::vector<std::vector<float>> MatrixMultiplication::multiply(std::vector<std::vector<float>> matrixA, std::vector<std::vector<float>> matrixB)
{
  A_height = matrixA.size();
  A_width = matrixA[0].size();
  B_height = A_width;
  B_width = matrixB.size();
  C_height = A_height;
  C_width = B_width;

  printf("Matrix sizes:\n  A: %d x %d\n  B: %d x %d\n  C: %d x %d\n",
         A_height, A_width, B_height, B_width, C_height, C_width);

  // Initialize OpenCL.
  if (!init_opencl())
  {
    return std::vector<std::vector<float>>(0, std::vector<float>(0));
  }

  // Initialize the problem data.
  // Requires the number of devices to be known.
  init_problem(matrixA, matrixB);

  // Run the kernel.
  std::vector<float> matrixC = run();
  std::vector<std::vector<float>> result = std::vector<std::vector<float>>(C_height, std::vector<float>(C_width));
  for(int y = 0; y < C_height; y++){
    for(int x = 0;  x < C_width; x++){
      result[y][x] = matrixC[y * C_width + x];
    }
  }

  // Free the resources allocated
  cleanup();
  
  return result;
}

/////// HELPER FUNCTIONS ///////

// Initializes the OpenCL objects.
bool MatrixMultiplication::init_opencl()
{
  cl_int status;

  printf("Initializing OpenCL\n");

  if (!setCwdToExeDir())
  {
    return false;
  }

  // Get the OpenCL platform.
  platform = findPlatform("Intel(R) CPU Runtime for OpenCL(TM)");
  if (platform == NULL)
  {
    printf("ERROR: Unable to find Intel(R) FPGA OpenCL platform.\n");
    return false;
  }

  // Query the available OpenCL device.
  device.reset(getDevices(platform, CL_DEVICE_TYPE_CPU, &num_devices));
  printf("Platform: %s\n", getPlatformName(platform).c_str());
  printf("Using %d device(s)\n", num_devices);
  for (unsigned i = 0; i < num_devices; ++i)
  {
    printf("  %s\n", getDeviceName(device[i]).c_str());
  }

  // Create the context.
  context = clCreateContext(NULL, num_devices, device, &oclContextCallback, NULL, &status);
  checkError(status, "Failed to create context");

  // Create the program for all device. Use the first device as the
  // representative device (assuming all device are of the same type).
  FILE *fp;
  char fileName[] = "matrix_mult.cl";
  char *source_str;
  size_t source_size;
  fp = fopen(fileName, "r");
  if (!fp)
  {
    printf("Error with loading");
    return 0;
  }
  source_str = (char *)malloc(MAX_SOURCE_SIZE);
  source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
  fclose(fp);
  program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
                                      (size_t *)&source_size, &status);

  // Build the program that was just created.
  status = clBuildProgram(program, 0, NULL, "", NULL, NULL);
  checkError(status, "Failed to build program");

  // Create per-device objects.
  queue.reset(num_devices);
  kernel.reset(num_devices);
  rows_per_device.reset(num_devices);
  input_a_buf.reset(num_devices);
  input_b_buf.reset(num_devices);
  output_buf.reset(num_devices);

  const unsigned num_block_rows = C_height / BLOCK_SIZE;

  for (unsigned i = 0; i < num_devices; ++i)
  {
    // Command queue.
    queue[i] = clCreateCommandQueue(context, device[i], CL_QUEUE_PROFILING_ENABLE, &status);
    checkError(status, "Failed to create command queue");

    // Kernel.
    const char *kernel_name = "matrixMult";
    kernel[i] = clCreateKernel(program, kernel_name, &status);
    checkError(status, "Failed to create kernel");

    // Determine the number of rows processed by this device.
    // First do this computation in block-rows.
    rows_per_device[i] = num_block_rows / num_devices; // this is the number of block-rows

    // Spread out the remainder of the block-rows over the first
    // N % num_devices.
    if (i < (num_block_rows % num_devices))
    {
      rows_per_device[i]++;
    }

    // Multiply by BLOCK_SIZE to get the actual number of rows.
    rows_per_device[i] *= BLOCK_SIZE;

    // Input buffers.
    // For matrix A, each device only needs the rows corresponding
    // to the rows of the output matrix. We specifically
    // assign this buffer to the first bank of global memory.
    input_a_buf[i] = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                    rows_per_device[i] * A_width * sizeof(float), NULL, &status);
    checkError(status, "Failed to create buffer for input A");

    // For matrix B, each device needs the whole matrix. We specifically
    // assign this buffer to the second bank of global memory.
    input_b_buf[i] = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                    B_height * B_width * sizeof(float), NULL, &status);
    checkError(status, "Failed to create buffer for input B");

    // Output buffer. This is matrix C, for the rows that are computed by this
    // device. We assign this buffer to the first bank of global memory,
    // although it is not material to performance to do so because
    // the reads from the input matrices are far more frequent than the
    // write to the output matrix.
    output_buf[i] = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
                                   rows_per_device[i] * C_width * sizeof(float), NULL, &status);
    checkError(status, "Failed to create buffer for output");
  }

  return true;
}

// Initialize the data for the problem. Requires num_devices to be known.
void MatrixMultiplication::init_problem(std::vector<std::vector<float>> matrixA, std::vector<std::vector<float>> matrixB)
{
  if (num_devices == 0)
  {
    checkError(-1, "No devices");
  }
  unsigned currentRow = 0;
  for (unsigned i = 0; i < num_devices; ++i)
  {
    input_a[i].reset(rows_per_device[i] * A_width);
    output[i].reset(rows_per_device[i] * C_width);

    for (unsigned j = 0; j < rows_per_device[i]; ++j)
    {
      for (unsigned k = 0; k < A_width; ++k)
      {
        input_a[i][j * A_width + k] = matrixA[currentRow][j];
      }
      ++currentRow;
    }
    ++currentRow;
  }

  input_b.reset(B_height * B_width);
  for (unsigned i = 0; i < B_height * B_width; ++i)
  {
    for (unsigned j = 0; j < B_width; ++j)
    {
      input_b[i] = matrixB[j][i];
    }
  }
}

std::vector<float> MatrixMultiplication::run()
{
  cl_int status;

  // Transfer inputs to each device. Each of the host buffers supplied to
  // clEnqueueWriteBuffer here is already aligned to ensure that DMA is used
  // for the host-to-device transfer.
  for (unsigned i = 0; i < num_devices; ++i)
  {
    status = clEnqueueWriteBuffer(queue[i], input_a_buf[i], CL_FALSE,
                                  0, rows_per_device[i] * A_width * sizeof(float), input_a[i], 0, NULL, NULL);
    checkError(status, "Failed to transfer input A");

    status = clEnqueueWriteBuffer(queue[i], input_b_buf[i], CL_FALSE,
                                  0, B_width * B_height * sizeof(float), input_b, 0, NULL, NULL);
    checkError(status, "Failed to transfer input B");
  }

  // Wait for all queues to finish.
  for (unsigned i = 0; i < num_devices; ++i)
  {
    clFinish(queue[i]);
  }

  // Launch kernels.
  // This is the portion of time that we'll be measuring for throughput
  // benchmarking.
  scoped_array<cl_event> kernel_event(num_devices);

  const double start_time = getCurrentTimestamp();
  for (unsigned i = 0; i < num_devices; ++i)
  {
    // Set kernel arguments.
    unsigned argi = 0;

    status = clSetKernelArg(kernel[i], argi++, sizeof(cl_mem), &output_buf[i]);
    checkError(status, "Failed to set argument %d", argi - 1);

    status = clSetKernelArg(kernel[i], argi++, sizeof(cl_mem), &input_a_buf[i]);
    checkError(status, "Failed to set argument %d", argi - 1);

    status = clSetKernelArg(kernel[i], argi++, sizeof(cl_mem), &input_b_buf[i]);
    checkError(status, "Failed to set argument %d", argi - 1);

    status = clSetKernelArg(kernel[i], argi++, sizeof(A_width), &A_width);
    checkError(status, "Failed to set argument %d", argi - 1);

    status = clSetKernelArg(kernel[i], argi++, sizeof(B_width), &B_width);
    checkError(status, "Failed to set argument %d", argi - 1);

    // Enqueue kernel.
    // Use a global work size corresponding to the size of the output matrix.
    // Each work-item computes the result for one value of the output matrix,
    // so the global work size has the same dimensions as the output matrix.
    //
    // The local work size is one block, so BLOCK_SIZE x BLOCK_SIZE.
    //
    // Events are used to ensure that the kernel is not launched until
    // the writes to the input buffers have completed.
    const size_t global_work_size[2] = {C_width, rows_per_device[i]};
    const size_t local_work_size[2] = {BLOCK_SIZE, BLOCK_SIZE};
    printf("Launching for device %d (global size: %zd, %zd)\n", i, global_work_size[0], global_work_size[1]);

    status = clEnqueueNDRangeKernel(queue[i], kernel[i], 2, NULL,
                                    global_work_size, local_work_size, 0, NULL, &kernel_event[i]);
    checkError(status, "Failed to launch kernel");
  }

  // Wait for all kernels to finish.
  clWaitForEvents(num_devices, kernel_event);

  const double end_time = getCurrentTimestamp();
  const double total_time = end_time - start_time;

  // Wall-clock time taken.
  printf("\nTime: %0.3f ms\n", total_time * 1e3);

  // Get kernel times using the OpenCL event profiling API.
  for (unsigned i = 0; i < num_devices; ++i)
  {
    cl_ulong time_ns = getStartEndTime(kernel_event[i]);
    printf("Kernel time (device %d): %0.3f ms\n", i, double(time_ns) * 1e-6);
  }

  // Compute the throughput (GFLOPS).
  // There are C_width * C_height output values, with each value
  // computed using A_width multiplies and adds.
  const float flops = (float)(2.0f * C_width * C_height * A_width / total_time);
  printf("\nThroughput: %0.2f GFLOPS\n\n", flops * 1e-9);

  // Release kernel events.
  for (unsigned i = 0; i < num_devices; ++i)
  {
    clReleaseEvent(kernel_event[i]);
  }

  // Read the result.
  for (unsigned i = 0; i < num_devices; ++i)
  {
    status = clEnqueueReadBuffer(queue[i], output_buf[i], CL_TRUE,
                                 0, rows_per_device[i] * C_width * sizeof(float), output[i], 0, NULL, NULL);
    checkError(status, "Failed to read output matrix");
  }

  // Verify results.
  //compute_reference();
  //verify();

  std::vector<float> result = std::vector<float>(C_width * C_height);
  for (unsigned y = 0, dev_index = 0; y < C_height; ++dev_index)
  {
    for (unsigned yy = 0; yy < rows_per_device[dev_index]; ++yy, ++y)
    {
      for (unsigned x = 0; x < C_width; ++x)
      {
        result[y * C_width + x] = output[dev_index][yy * C_width + x];
      }
    }
  }
  return result;
}

// Free the resources allocated during initialization
void MatrixMultiplication::cleanup()
{
  for (unsigned i = 0; i < num_devices; ++i)
  {
    if (kernel && kernel[i])
    {
      clReleaseKernel(kernel[i]);
    }
    if (queue && queue[i])
    {
      clReleaseCommandQueue(queue[i]);
    }
    if (input_a_buf && input_a_buf[i])
    {
      clReleaseMemObject(input_a_buf[i]);
    }
    if (input_b_buf && input_b_buf[i])
    {
      clReleaseMemObject(input_b_buf[i]);
    }
    if (output_buf && output_buf[i])
    {
      clReleaseMemObject(output_buf[i]);
    }
  }
  if (program)
  {
    clReleaseProgram(program);
  }
  if (context)
  {
    clReleaseContext(context);
  }
}
