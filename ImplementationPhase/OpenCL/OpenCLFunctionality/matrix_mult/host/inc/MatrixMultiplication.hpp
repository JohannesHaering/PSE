#ifndef MATRIX_MULTIPLICATION_H_
#define MATRIX_MULTIPLICATION_H_


#ifndef MEM_SIZE
#define MEM_SIZE (128)
#endif
#ifndef MAX_SOURCE_SIZE
#define MAX_SOURCE_SIZE (0x100000)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>

#include "matrixMult.h"
#include "AOCLUtils/aocl_utils.h"
#include "CL/cl.h"

class MatrixMultiplication
{
public:
    bool init_opencl();
    void init_problem(std::vector<std::vector<float>> matrixA, std::vector<std::vector<float>> matrixB);
    std::vector<float> run();
    void cleanup();
    std::vector<std::vector<float>> multiply(std::vector<std::vector<float>> matrixA, std::vector<std::vector<float>> matrixB);

    // OpenCL runtime configuration
    cl_platform_id platform = NULL;
    unsigned num_devices = 0;
    scoped_array<cl_device_id> device; // num_devices elements
    cl_context context = NULL;
    scoped_array<cl_command_queue> queue; // num_devices elements
    cl_program program = NULL;
    scoped_array<cl_kernel> kernel; // num_devices elements

    scoped_array<cl_mem> input_a_buf; // num_devices elements
    scoped_array<cl_mem> input_b_buf; // num_devices elements
    scoped_array<cl_mem> output_buf;  // num_devices elements

    // Problem data.
    unsigned A_height;
    unsigned A_width;
    unsigned B_height = A_width;
    unsigned B_width = 2;
    unsigned C_height = A_height;
    unsigned C_width = B_width;

    scoped_array<scoped_aligned_ptr<float>> input_a; // num_devices elements
    scoped_aligned_ptr<float> input_b;
    scoped_array<scoped_aligned_ptr<float>> output; // num_devices elements

    scoped_array<float> ref_output;
    scoped_array<unsigned> rows_per_device; // num_devices elements
};
#endif