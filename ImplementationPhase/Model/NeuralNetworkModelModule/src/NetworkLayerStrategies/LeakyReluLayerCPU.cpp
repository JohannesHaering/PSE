#include "LeakyReLuLayerCPU.hpp"
#include "MatrixDefine.hpp"

#include <vector>
#include <CL/cl.h>

TENSOR(float) LeakyReLuLayerCPU::forward(TENSOR(float) input_data)
{
	size_t MAX_SOURCE_SIZE = 0x100000;
    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[b].size(); z++)
            for (int y = 0; y < input_data[b][z].size(); y++)
            {
                std::vector<float> arr = input_data[b][z][y];

                float *hostInput = (float *)malloc(sizeof(float) * arr.size());
                float *hostOutput = (float *)malloc(sizeof(float) + arr.size());

                for (int j = 0; j < arr.size(); j++)
                    hostInput[j] = arr[j];

                FILE *fp;
                char *source_str;
                size_t source_size;

                fp = fopen("..//OpenCL//LeakyRelu.cl", "r");
                if (!fp)
                {
                    fprintf(stderr, "Failed to load kernel.\n");
                    return TENSOR(float)(0, MATRIX_3D(float)(0, MATRIX_2D(float)(0, std::vector<float>(0))));
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
                cl_mem input_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                                      sizeof(float) * arr.size(), NULL, &ret);
                cl_mem output_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,
                                                       sizeof(float) * arr.size(), NULL, &ret);

                ret = clEnqueueWriteBuffer(command_queue, input_mem_obj, CL_TRUE, 0,
                                           sizeof(float) * arr.size(), hostInput, 0, NULL, NULL);

                // Create a program from the kernel source
                cl_program program = clCreateProgramWithSource(context, 1,
                                                               (const char **)&source_str, (const size_t *)&source_size, &ret);

                // Build the program
                ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

                // Create the OpenCL kernel
                cl_kernel kernel = clCreateKernel(program, "leakyRelu", &ret);

                cl_command_queue commands = clCreateCommandQueue(context, device_id, 0, &ret);

                //Launch OpenCL kernel
                size_t localWorkSize[2], globalWorkSize[2];

                ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&output_mem_obj);
                ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&input_mem_obj);
                ret |= clSetKernelArg(kernel, 3, sizeof(int), (void *)&(arr.size()));
                ret |= clSetKernelArg(kernel, 4, sizeof(int), (void *)&(arr.size()));

                // Execute the OpenCL kernel on the list
                size_t global_item_size = sizeof(hostOutput) / sizeof(float); // Process the entire lists
                size_t local_item_size = 64;                                  // Divide work items into groups of 64
                ret = clEnqueueNDRangeKernel(commands, kernel, 1, NULL,
                                             &global_item_size, &local_item_size, 0, NULL, NULL);

                // Read the memory buffer C on the device to the local variable C
                ret = clEnqueueReadBuffer(commands, hostOutput, CL_TRUE, 0, sizeof(output_mem_obj), A.size(), 0, NULL, NULL);

                std::vector<float> output = std::vector<float>();
                for (int x = 0; y < arr.size(); y++)
                    output.push_back(hostOutput[x]);

				input_data[b][z][y] = output;

                // release OpenCL resources
                clReleaseMemObject(input_mem_obj);
                clReleaseMemObject(output_mem_obj);
                clReleaseProgram(program);
                clReleaseKernel(kernel);
                clReleaseCommandQueue(commands);
                clReleaseContext(context);

                //release host memory
                free(hostInput);
                free(hostOutput);
            }

    return input_data;
}

TENSOR(float) LeakyReLuLayerCPU::backprob(TENSOR(float) updates)
{
    TENSOR(float) output = updates;
    for (int b = 0; b < updates.size(); b++)
        for (int z = 0; z < updates[0].size(); z++)
            for (int y = 0; y < updates[0][0].size(); y++)
                for (int x = 0; x < updates[0][0][0].size(); x++)
					output[b][z][y][x] = updates[b][z][y][x] > 0 ? updates[b][z][y][x] : 100 * updates[b][z][y][z];
    return output;
}