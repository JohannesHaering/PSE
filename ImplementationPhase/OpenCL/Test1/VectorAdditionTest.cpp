#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <ctime>
#include <limits>
#include <CL/cl.h>

#include "oclobject.hpp"
#include "basic.hpp"


std::vector<float> addVector(std::vector<float> a, std::vector<float> b)
{
    float *A = (float *)malloc(sizeof(float) * a.size());
    float *B = (float *)malloc(sizeof(float) * b.size());
    float *C = (float *)malloc(sizeof(float) * a.size());
    float *Res = (float *)malloc(sizeof(float) * a.size());
    float *D = (float *)malloc(sizeof(float) * a.size());

    int heightA = a.size();
    int heightB = b.size();
    int heightC = a.size();

    std::vector<float> result = std::vector<float>(heightC);

    // feed in the input
    for (int y = 0; y < a.size(); y++)
        A[y] = a[y];

    for (int y = 0; y < b.size(); y++)
        B[y] = b[y];

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


    std::cout<< "Load Data" << std::endl;
    FILE *fp;
    char fileName[] = "./VectorAddition.cl";
    char *source_str;
    size_t source_size;
    int col = heightC;
    /* Load the source code containing the kernel*/
    fp = fopen(fileName, "r");
    if (!fp)
    {
        return std::vector<float>();
    }
    source_str = (char *)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    std::cout<< "Get plattform and device info" << std::endl;
    /* Get Platform and Device Info */
    ret =clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);

    /* Create OpenCL context */
    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

    /* Create Command Queue */
    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    std::cout<< "Create buffer" << std::endl;
    /* Create Memory Buffer */
    memobjA = clCreateBuffer(context, CL_MEM_READ_WRITE, heightA * sizeof(float), NULL, &ret);
    memobjB = clCreateBuffer(context, CL_MEM_READ_WRITE, heightB * sizeof(float), NULL, &ret);
    memobjC = clCreateBuffer(context, CL_MEM_READ_WRITE, heightC * sizeof(float), NULL, &ret);
    colC = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);

    // Copy the lists A and B to their respective memory buffers
    ret = clEnqueueWriteBuffer(command_queue, memobjA, CL_TRUE, 0,
                               heightA * sizeof(int), A, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, memobjB, CL_TRUE, 0,
                               heightB * sizeof(int), B, 0, NULL, NULL);
    ret = clEnqueueWriteBuffer(command_queue, colC, CL_TRUE, 0, sizeof(int), &col, 0, NULL, NULL);

    /* Create Kernel Program from the source */
    program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
                                        (const size_t *)&source_size, &ret);

    std::cout<< "Build programm" << std::endl;
    /* Build Kernel Program */
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    /* Create OpenCL Kernel */
    kernel = clCreateKernel(program, "vectorAddition", &ret);

    /* Set OpenCL Kernel Arguments */
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&memobjB);
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&memobjC);
    //ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
    ret = clSetKernelArg(kernel, 4, sizeof(int), (void *)&col);

    std::cout<< "Executue kernel" << std::endl;
    /* Execute OpenCL Kernel */
    //ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
    size_t globalThreads[1] = {heightB};
    size_t localThreads[1] = {16};

    clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, globalThreads, localThreads, NULL, 0, NULL);
    /* Copy results from the memory buffer */
    ret = clEnqueueReadBuffer(command_queue, memobjC, CL_TRUE, 0,
                              heightC * sizeof(float), Res, 0, NULL, NULL);

    std::cout<< "Load result" << std::endl;
    for (int j = 0; j < heightC; j++)
    {
        result[j] = (C[j]);
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


int main()
{
    std::vector<float> A = std::vector<float>(10);
    std::vector<float> B = std::vector<float>(10);

    for (int i = 0; i < 10; i++)
    {
        A[i] = i;
        B[i] = 9 - i;
    }

    std::vector<float> C = addVector(A, B);

    for (int i = 0; i < 10; i++)
        std::cout << "C[i] = " << C[i] << std::endl;

    return 0;
}
