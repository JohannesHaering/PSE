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
    // Get kernel code
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


    return 0;
}