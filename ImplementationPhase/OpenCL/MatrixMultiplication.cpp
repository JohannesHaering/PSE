// Sligthly modified example from intels website
// https://software.intel.com/en-us/opencl-sdk/training

#include <iostream>
#include <ctime>
#include <limits>
#include <cmath>
#include <vector>

#include <CL/cl.h>

#include "basic.hpp"
#include "cmdoptions.hpp"
#include "oclobject.hpp"

using namespace std;

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

int main()
{
    float *A = (float *)malloc(sizeof(float) * widthA * heightA);
    float *B = (float *)malloc(sizeof(float) * widthB * heightB);
    float *C = (float *)malloc(sizeof(float) * widthC * heightC);
    float *Res = (float *)malloc(sizeof(float) * widthC * heightC);
    float *D = (float *)malloc(sizeof(float) * widthC * heightC);

    for (int i = 0; i < widthA; i++)
    {
        for(int j=0;j       {
            float p = (rand() % 100) / 7.0;
            *(A + i * heightA + j) = rand() % 100 + p;
            cout << *(A + i * heightA + j) << endl;
        }
    }

    for (int i = 0; i < widthB; i++)
    {
        for(int j=0; j      {
            float p = (rand() % 100) / 7.0;
            *((B + i * heightB + j)) = rand() % 100 + p;
           cout << *(B + i * heightA + j) << endl;
        }
    }

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
    char fileName[] = "./MatrixMultiplication.cl";
    char *source_str;
    size_t source_size;
    int row = widthA;
    int col = heightC;
    /* Load the source code containing the kernel*/
    fp = fopen(fileName, "r");
    if (!fp)
    {
        cout <<  "Failed to load kernel.\n" << endl;
        exit(1);
    }
    source_str = (char *)malloc(MAX_SOURCE_SIZE);
    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose(fp);

    /* Get Platform and Device Info */
    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

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
    kernel = clCreateKernel(program, "matrixMultiplication", &ret);

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

    cout << ("\nResult\n") << endl;
    for (int i = 0; i < widthA; i++)
    {
        for (int j = 0; j < heightC; j++)
        {

            cout << *(Res + i * heightC + j) << endl;
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
    return 0;
}