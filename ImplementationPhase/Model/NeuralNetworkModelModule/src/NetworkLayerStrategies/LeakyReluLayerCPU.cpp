#include "LeakyReLuLayerCPU.hpp"
#include "MatrixDefine.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <CL/cl.h>

#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

TENSOR(float)
LeakyReLuLayerCPU::forward(TENSOR(float) input_data)
{
    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[b].size(); z++)
            for (int y = 0; y < input_data[b][z].size(); y++)
            {
                std::vector<float> arr = input_data[b][z][y];

                float *A = (float *)malloc(sizeof(float) * arr.size());
                float *C = (float *)malloc(sizeof(float) * arr.size());
                float *Res = (float *)malloc(sizeof(float) * arr.size());
                float *D = (float *)malloc(sizeof(float) * arr.size());

                int heightA = arr.size();
                int heightC = arr.size();

                std::vector<float> result = std::vector<float>(heightC);

                // feed in the input
                for (int y = 0; y < a.size(); y++)
                    A[y] = arr[y];

                cl_device_id device_id = NULL;
                cl_context context = NULL;
                cl_command_queue command_queue = NULL;
                cl_mem memobjA = NULL;
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
                char fileName[] = "./../../OpenCL/LeakyRelu.cl";
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

                /* Get Platform and Device Info */
                ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
                ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);

                /* Create OpenCL context */
                context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

                /* Create Command Queue */
                command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

                /* Create Memory Buffer */
                memobjA = clCreateBuffer(context, CL_MEM_READ_WRITE, heightA * sizeof(float), NULL, &ret);
                memobjC = clCreateBuffer(context, CL_MEM_READ_WRITE, heightC * sizeof(float), NULL, &ret);
                colC = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int), NULL, &ret);

                // Copy the lists A and B to their respective memory buffers
                ret = clEnqueueWriteBuffer(command_queue, memobjA, CL_TRUE, 0,
                                           heightA * sizeof(int), A, 0, NULL, NULL);
                ret = clEnqueueWriteBuffer(command_queue, colC, CL_TRUE, 0, sizeof(int), &col, 0, NULL, NULL);

                /* Create Kernel Program from the source */
                program = clCreateProgramWithSource(context, 1, (const char **)&source_str,
                                                    (const size_t *)&source_size, &ret);

                /* Build Kernel Program */
                ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

                /* Create OpenCL Kernel */
                kernel = clCreateKernel(program, "leakyRelu", &ret);

                /* Set OpenCL Kernel Arguments */
                ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
                ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&memobjC);
                //ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobjA);
                ret = clSetKernelArg(kernel, 4, sizeof(int), (void *)&col);
                /* Execute OpenCL Kernel */
                //ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
                size_t globalThreads[1] = {heightA};
                size_t localThreads[1] = {16};

                clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, globalThreads, localThreads, NULL, 0, NULL);
                /* Copy results from the memory buffer */
                ret = clEnqueueReadBuffer(command_queue, memobjC, CL_TRUE, 0,
                                          heightC * sizeof(float), Res, 0, NULL, NULL);

                for (int j = 0; j < heightC; j++)
                {
                    result[j] = *(Res + j);
                }

                ret = clFlush(command_queue);
                ret = clFinish(command_queue);
                ret = clReleaseKernel(kernel);
                ret = clReleaseProgram(program);
                ret = clReleaseMemObject(memobjA);
                ret = clReleaseMemObject(memobjC);
                ret = clReleaseCommandQueue(command_queue);
                ret = clReleaseContext(context);

                free(source_str);

                input_data[b][z][y] result;
            }

    return input_data;
}

TENSOR(float)
LeakyReLuLayerCPU::backprob(TENSOR(float) updates)
{
    TENSOR(float)
    output = updates;
    for (int b = 0; b < updates.size(); b++)
        for (int z = 0; z < updates[0].size(); z++)
            for (int y = 0; y < updates[0][0].size(); y++)
                for (int x = 0; x < updates[0][0][0].size(); x++)
                    output[b][z][y][x] = updates[b][z][y][x] > 0 ? updates[b][z][y][x] : 0.01 * updates[b][z][y][z];
    return output;
}