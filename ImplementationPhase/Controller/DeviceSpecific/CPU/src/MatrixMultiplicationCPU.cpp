#include "MatrixMultiplicationCPU.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <CL/cl.h>

std::vector<std::vector<float>> *MatrixMultiplicationCPU::mult(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
{
    // OpenCL device memory for matrices
    cl_mem d_A;
    cl_mem d_B;
    cl_mem d_C;

    // allocate memory for the input matrices and the output matrix on the host device
    float *hostA = (float *)malloc(sizeof(float) * A.size() * A[0].size());
    float *hostB = (float *)malloc(sizeof(float) * B.size() * B[0].size());
    float *hostC = (float *)malloc(sizeof(float) * A.size() * B[0].size());

    // feed in the input
    for (int y = 0; y < A.size(); y++)
        for (int x = 0; x < A[y].size(); x++)
            hostA[y * A.size() + x] = A[y][x];

    for (int y = 0; y < B.size(); y++)
        for (int x = 0; x < B[y].size(); x++)
            hostB[y * B.size() + x] = A[y][x];

    // Load the kernel source code into the array source_str
    FILE *fp;
    char *source_str;
    size_t source_size;

    fp = fopen("..//OpenCL//MatrixMultiplication.cl", "r");
    if (!fp)
    {
        fprintf(stderr, "Failed to load kernel.\n");
        return nullptr;
    }
    source_str = (char *)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    // Get platform and device information
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
                         &device_id, &ret_num_devices);

    // Create an OpenCL context
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    // Create memory buffers on the device for each matrix
    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                      sizeof(float) * A.size() * A[0].size(), NULL, &ret);
    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                      sizeof(float) * B.size() * B[0].size(), NULL, &ret);
    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY,
                                      sizeof(float) * A.size() * B[0].size(), NULL, &ret);

    // Copy the lists A and B to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0,
                               sizeof(float) * A.size() * A[0].size(), hostA, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0,
                               sizeof(float) * B.size() * B[0].size(), hostB, 0, NULL, NULL);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,
                                                   (const char **)&source_str, (const size_t *)&source_size, &ret);

    // Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "matrix_multiplication", &ret);

    cl_command_queue  commands = clCreateCommandQueue(context, device_id, 0, &ret);

    //Launch OpenCL kernel
    size_t localWorkSize[2], globalWorkSize[2];

    int wA = A.size();
    int wC = A.size();
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&c_mem_obj);
    ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&a_mem_obj);
    ret |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&b_mem_obj);
    ret |= clSetKernelArg(kernel, 3, sizeof(int), (void *)&wA);
    ret |= clSetKernelArg(kernel, 4, sizeof(int), (void *)&wC);

    // Execute the OpenCL kernel on the list
    size_t global_item_size = sizeof(hostC) / sizeof(float); // Process the entire lists
    size_t local_item_size = 64;                             // Divide work items into groups of 64
    ret = clEnqueueNDRangeKernel(commands, kernel, 1, NULL,
                                 &global_item_size, &local_item_size, 0, NULL, NULL);

    // Read the memory buffer C on the device to the local variable C
    ret = clEnqueueReadBuffer(commands, hostC, CL_TRUE, 0, sizeof(c_mem_obj), A.size(), 0, NULL, NULL);

    std::vector<std::vector<float>> C = std::vector<std::vector<float>>();
    for (int y = 0; y < A.size(); y++)
    {
        std::vector<float> row = std::vector<float>();
        for (int x = 0; B[0].size(); x++)
            row.push_back(hostC[y * A.size() + x]);
        C.push_back(row);
    }

    return C;
}
