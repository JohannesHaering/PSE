#include "MatrixMultiplicationCPU.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <CL/cl.h>

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

/*static std::vector<std::vector<float>> MatrixMultiplicationCPU::mult(std::vector<std::vector<float>> A, std::vector<std::vector<float>> B)
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
            hostB[y * B.size() + x] = B[y][x];

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
    cl_kernel kernel = clCreateKernel(program, "matrixMul", &ret);

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

    // release OpenCL resources
    clReleaseMemObject(a_mem_obj);
    clReleaseMemObject(b_mem_obj);
    clReleaseMemObject(c_mem_obj);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);
 
    //release host memory
    free(hostA);
    free(hostB);
    free(hostC);

    return C;
}*/

std::vector<std::vector<float>> MatrixMultiplicationCPU::mult(std::vector<std::vector<float>> iA, std::vector<std::vector<float>> iB)
{
    float *A = (float *)malloc(sizeof(float) * iA.size() * iA[0].size());
    float *B = (float *)malloc(sizeof(float) * iB.size() * iB[0].size());
    float *C = (float *)malloc(sizeof(float) * iA.size() * iB[0].size());
    float *Res = (float *)malloc(sizeof(float) * iA.size() * iB[0].size());
    float *D = (float *)malloc(sizeof(float) * iA.size() * iB[0].size());

    int widthA = iA[0].size();
    int heightA = iA.size();
    int widthB = iB[0].size();
    int heightB = iB.size();
    int widthC = iB[0].size();
    int heightC = iA.size();

    std::vector<std::vector<float>> result = std::vector<std::vector<float>>(heightC, std::vector<float>(widthC));

    // feed in the input
    for (int y = 0; y < iA.size(); y++)
        for (int x = 0; x < iA[y].size(); x++)
            A[y * iA.size() + x] = iA[y][x];

    for (int y = 0; y < iB.size(); y++)
        for (int x = 0; x < iB[y].size(); x++)
            B[y * iB.size() + x] = iB[y][x];

    cl_device_id device_id = NULL;
    cl_context context = NULL;
    cl_command_queue command_queue = NULL;
    cl_mem memobjA = NULL;
    cl_mem memobjB = NULL;
    cl_mem memobjC = NULL;
    cl_mem rowA = NULL;
    cl_mem colC = NULL;
    cl_program program = NULL;
    cl_kernel kernel = NULL;
    cl_platform_id platform_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret;

    //char string[MEM_SIZE];

    FILE *fp;
    char fileName[] = "./../../OpenCL/MatrixMultiplication.cl";
    char *source_str;
    size_t source_size;
    int row = widthA;
    int col = heightC;
    /* Load the source code containing the kernel*/
    fp = fopen(fileName, "r");
    if (!fp)
    {
        return std::vector<std::vector<float>>(0, std::vector<float>());
    }
    source_str = (char *)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    /* Get Platform and Device Info */
    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);

    /* Create OpenCL context */
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    /* Create Command Queue */
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    /* Create Memory Buffer */
    memobjA = clCreateBuffer(context, CL_MEM_READ_WRITE, widthA * heightA * sizeof(float), NULL, &ret);
    memobjB = clCreateBuffer(context, CL_MEM_READ_WRITE, widthB * heightB * sizeof(float), NULL, &ret);
    memobjC = clCreateBuffer(context, CL_MEM_READ_WRITE, widthC * heightC * sizeof(float), NULL, &ret);
    rowA = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);
    colC = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);

    // Copy the lists A and B to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, memobjA, CL_TRUE, 0,
                               widthA * heightA * sizeof(int), A, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, memobjB, CL_TRUE, 0,
                               widthB * heightB * sizeof(int), B, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, rowA, CL_TRUE, 0, sizeof(int), &row, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, colC, CL_TRUE, 0, sizeof(int), &col, 0, NULL, NULL);

    /* Create Kernel Program from the source */
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
                                        (const size_t *)&source_size, &ret);

    /* Build Kernel Program */
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    /* Create OpenCL Kernel */
    kernel = clCreateKernel(program, "matrixMul", &ret);

    /* Set OpenCL Kernel Arguments */
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&memobjB);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&memobjC);
    //ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
    ret = clSetKernelArg(kernel, 3, sizeof(int), (void *)&row);
    ret = clSetKernelArg(kernel, 4, sizeof(int), (void *)&col);
    /* Execute OpenCL Kernel */
    //ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
    size_t globalThreads[2] = {widthA, heightB};
    size_t localThreads[2] = {16, 16};

    clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, globalThreads, localThreads, NULL, 0, NULL);
    /* Copy results from the memory buffer */
    ret = clEnqueueReadBuffer(command_queue, memobjC, CL_TRUE, 0,
                              widthA * heightC * sizeof(float), Res, 0, NULL, NULL);

    for (int i = 0; i < widthA; i++)
    {
        for (int j = 0; j < heightC; j++)
        {
            result[j][i] = *(Res + i * heightC + j);
        }
    }

    ret = clFlush(command_queue);
    ret = clFinish(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(memobjA);
    ret = clReleaseMemObject(memobjB);
    ret = clReleaseMemObject(memobjC);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);

    free(source_str);
    
    return result;
}
