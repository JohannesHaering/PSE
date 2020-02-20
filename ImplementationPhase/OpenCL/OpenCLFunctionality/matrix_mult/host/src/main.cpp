#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "matrixMult.h"
#include "AOCLUtils/aocl_utils.h"
#include "CL/cl.h"

using namespace aocl_utils;

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

// OpenCL runtime configuration
cl_platform_id platform = NULL;
unsigned num_devices = 0;
scoped_array<cl_device_id> device; // num_devices elements
cl_context context = NULL;
scoped_array<cl_command_queue> queue; // num_devices elements
cl_program program = NULL;
scoped_array<cl_kernel> kernel; // num_devices elements
#if USE_SVM_API == 0
scoped_array<cl_mem> input_a_buf; // num_devices elements
scoped_array<cl_mem> input_b_buf; // num_devices elements
scoped_array<cl_mem> output_buf;  // num_devices elements
#endif                            /* USE_SVM_API == 0 */
// Problem data.
unsigned A_height = 4;
unsigned A_width = 4 ;
const unsigned &B_height = A_width;
unsigned B_width = 4;
const unsigned &C_height = A_height;
const unsigned &C_width = B_width;

scoped_array<scoped_aligned_ptr<float>> input_a; // num_devices elements
scoped_aligned_ptr<float> input_b;
scoped_array<scoped_aligned_ptr<float>> output; // num_devices elements

scoped_array<float> ref_output;
scoped_array<unsigned> rows_per_device; // num_devices elements

// Function prototypes
bool init_opencl();
void init_problem(std::vector<float> matrixA, std::vector<float> matrixB);
std::vector<float> run();
void compute_reference();
void verify();
void cleanup();

// Entry point.
int main(int argc, char **argv)
{
  printf("Generating input matrices\n");
  input_a.reset(num_devices);
  output.reset(num_devices);
  std::vector<float> matrixA = std::vector<float>(A_height * A_width);
  for (int y = 0; y < A_height; y++)
  {
    for (int x = 0; x < A_width; x++)
    {
      matrixA[y * A_width + x] = y * x;
    }
    printf("Done row of A\n");
  }

  std::vector<float> matrixB = std::vector<float>(B_height * B_width);
  for (int y = 0; y < B_height; y++)
  {
    for (int x = 0; x < B_width; x++)
    {
      matrixB[y * B_width + x] = y * x;
    }
    printf("Done row of B\n");
  }

  printf("done generating\n");

  printf("Matrix sizes:\n  A: %d x %d\n  B: %d x %d\n  C: %d x %d\n",
         A_height, A_width, B_height, B_width, C_height, C_width);

  // Initialize OpenCL.
  if (!init_opencl())
  {
    return -1;
  }

  // Initialize the problem data.
  // Requires the number of devices to be known.
  init_problem(matrixA, matrixB);

  // Run the kernel.
  std::vector<float> matrixC = run();

  std::cout << matrixC[0] << std::endl;
  std::cout << matrixC[1] << std::endl;
  std::cout << matrixC[2] << std::endl;
  std::cout << matrixC[3] << std::endl;

  // Free the resources allocated
  cleanup();

  return 0;
}

/////// HELPER FUNCTIONS ///////

// Initializes the OpenCL objects.
bool init_opencl()
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
void init_problem(std::vector<float> matrixA, std::vector<float> matrixB)
{
  if (num_devices == 0)
  {
    checkError(-1, "No devices");
  }

  for (unsigned i = 0; i < num_devices; ++i)
  {
    input_a[i].reset(rows_per_device[i] * A_width);
    output[i].reset(rows_per_device[i] * C_width);

    for (unsigned j = 0; j < rows_per_device[i] * A_width; ++j)
    {
      input_a[i][j] = matrixA[i * A_width + +j];
    }
  }

  input_b.reset(B_height * B_width);
  for (unsigned i = 0; i < B_height * B_width; ++i)
  {
    input_b[i] = matrixB[i];
  }
}

void run()
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

void compute_reference()
{
  // Compute the reference output.
  printf("Computing reference output\n");
  ref_output.reset(C_height * C_width);

  for (unsigned y = 0, dev_index = 0; y < C_height; ++dev_index)
  {
    for (unsigned yy = 0; yy < rows_per_device[dev_index]; ++yy, ++y)
    {
      for (unsigned x = 0; x < C_width; ++x)
      {
        // Compute result for C(y, x)
        float sum = 0.0f;
        for (unsigned k = 0; k < A_width; ++k)
        {
          sum += input_a[dev_index][yy * A_width + k] * input_b[k * B_width + x];
        }
        ref_output[y * C_width + x] = sum;
      }
    }
  }
}

void verify()
{
  printf("Verifying\n");

  // Compute the L^2-Norm of the difference between the output and reference
  // output matrices and compare it against the L^2-Norm of the reference.
  float diff = 0.0f;
  float ref = 0.0f;
  for (unsigned y = 0, dev_index = 0; y < C_height; ++dev_index)
  {
    for (unsigned yy = 0; yy < rows_per_device[dev_index]; ++yy, ++y)
    {
      for (unsigned x = 0; x < C_width; ++x)
      {
        const float o = output[dev_index][yy * C_width + x];
        const float r = ref_output[y * C_width + x];
        const float d = o - r;
        diff += d * d;
        ref += r * r;
      }
    }
  }

  const float diff_l2norm = sqrtf(diff);
  const float ref_l2norm = sqrtf(ref);
  const float error = diff_l2norm / ref_l2norm;
  const bool pass = error < 1e-6;
  printf("Verification: %s\n", pass ? "PASS" : "FAIL");
  if (!pass)
  {
    printf("Error (L^2-Norm): %0.3g\n", error);
  }
}

// Free the resources allocated during initialization
void cleanup()
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
