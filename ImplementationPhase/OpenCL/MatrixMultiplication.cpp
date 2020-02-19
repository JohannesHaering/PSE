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


// Check validity for multiplication of square matrices: Cresult == alpha*A*Btransposed(B) + beta*Cinit.
// Samll simplification here: the procedure assumes that initial C values are all zeros,
// so beta is not actually used.
    //T alpha, T beta // coefficient to compute
bool checkValidity (
    const cl_float* A,     // left input matrix, column-major
    const cl_float* B,     // right input matrix, column-major or row-major depending on Btransposed argument
    const cl_float* C,     // output matrix, column-major
    size_t size,    // number of column in each of the matrices
    size_t ldabc,   // row stride: the number of cl_float elements in one row (including optional padding)
    bool Btransposed
)
{
    cout << "Validate output..." << flush;

    // Btransposed == false, lstride = 1
    Btransposed = false;
    size_t lstride = Btransposed ? ldabc : 1;
    size_t jstride = Btransposed ? 1 : ldabc;
    cout << "lstride, jstride" << lstride << " " << jstride << flush;
    // Estimate error tolerance for a given type T and relying on the fact
    // that initial matrix values are from [0, 1]
    cl_float max_value = 1;
    cl_float error_tol = float(2) * max_value * max_value * float(2) * size * numeric_limits<float>::epsilon();

    for(size_t i = 0; i < size; ++i)
    {
        for(size_t j = 0; j < size; ++j)
        {
            // compute golden value for c[i][j] element
            cl_float accum = 0;
            for(size_t l = 0; l < size; ++l)
            {
              cout << A[l*ldabc + i] << "\n";
              cout << B[l*lstride + j*jstride]<<"\n";
              cout.flush();
              accum += A[l*ldabc + i] * B[l*lstride + j*jstride];
            }

            cl_float golden = accum;
            cout<<C[j*ldabc+i];
            cout.flush();
            cl_float absdiff = abs(C[j*ldabc+i] - golden);
            if(absdiff > error_tol)
            {
                cout << " FAILED\n";
                cerr.precision(std::numeric_limits<cl_float>::digits10);
                cerr << "\nVALIDATION FAILED!!!\n    reference" << "[" << i << ", " << j << "] = "
                     << golden << ",\n    calculated" << "[" << i << ", " << j << "] = "
                     << C[j*ldabc+i]
                     << ",\n    absolute difference" << "[" << i << ", " << j << "] = " << absdiff << "\n"
                     << "Further validation was stopped\n\n";
                return false;
            }
        }
    }

    std::cout << " PASSED\n";
    return true;
}


// The main GEMM function with all application specific
// OpenCL host side code.
template <typename T>
void gemm (
    CmdParserGEMM& cmdparser,
    OpenCLBasic& oclobjects,
    OpenCLProgramOneKernel& executable,
    std::vector<float> inputA,
    std::vector<float> inputB,
    int matrixSize
)
{
    // -----------------------------------------------------------------------
    // Calculating, allocating and initializing host-side memory
    // -----------------------------------------------------------------------

    // Query for necessary alignment for each row
    // Each row is aligned by requirements of OpenCL to achieve better
    // performance in comparison to not aligned data
    size_t rowAlignment = requiredOpenCLAlignment(oclobjects.device);

    // a couple of sanity checks to ensure correctness of the further math with the returned value
    assert(rowAlignment >= sizeof(cl_float)); // must be
    assert((rowAlignment & (rowAlignment - 1)) == 0); // test for power of 2

    // the next call checks for various OpenCL bounds to proactively
    // handle possible errors like out of memory
    cmdparser.validateParameters(oclobjects, executable, sizeof(cl_float), rowAlignment);

    size_t size = matrixSize;
    cout
        << "Running gemm_" << cmdparser.kernel.getValue()
        << " kernel with matrix size: " << size << "x" << size << "\n";

    // Ensures that each matrix memory row is aligned
    size_t stride = (size*sizeof(cl_float) + rowAlignment - 1) & ~(rowAlignment - 1);
    cout << "Memory row stride to ensure necessary alignment: " << stride << " bytes\n";
    // calculate row stride in elements of T
    stride /= sizeof(cl_float);
    assert(size <= stride);

    if(stride/sizeof(cl_float) > size_t(numeric_limits<cl_int>::max()))
    {
        throw Error(
            "Memory row stride in elements " + to_str(stride/sizeof(cl_float)) +
            " cannot be represented as type int, which can be maximum " +
            to_str(numeric_limits<cl_int>::max()) + "."
        );
    }

    size_t matrix_memory_size = size*stride*sizeof(cl_float);
    cout << "Size of memory region for one matrix: " << matrix_memory_size << " bytes\n";

    // Allocate aligned memory for matrices to use them in
    // buffers with CL_MEM_USE_HOST_PTR.
    // OpenCLDeviceAndHostMemory is used just for
    // convenient resource deallocation:
    // a pair of pointer and cl_mem object; cl_mem object is
    // be creater later.

    size_t alignmentForPtr = zeroCopyPtrAlignment(oclobjects.device);
    size_t alignedSize = zeroCopySizeAlignment(matrix_memory_size, oclobjects.device);

    OpenCLDeviceAndHostMemory<cl_float> matrix_A;
    matrix_A.host = (cl_float*)aligned_malloc(alignedSize, alignmentForPtr);

    OpenCLDeviceAndHostMemory<cl_float> matrix_B;
    matrix_B.host = (cl_float*)aligned_malloc(alignedSize, alignmentForPtr);

    OpenCLDeviceAndHostMemory<cl_float> matrix_C;
    matrix_C.host = (cl_float*)aligned_malloc(alignedSize, alignmentForPtr);

    // Initialize matrices row by row.
    for(size_t i = 0; i < size; ++i)
    {
        cl_float* row_A = matrix_A.host + i*stride;
        cl_float* row_B = matrix_B.host + i*stride;
        cl_float* row_C = matrix_C.host + i*stride;

        // To simplify validation a bit, we initialize C matrix with all zeros.
        // It should not affect performance, which should be identical to
        // the general case.
        std::fill(row_C, row_C + size, cl_float(0));
    }
  
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        matrix_A.host[j*stride + i] = inputA[i];
        matrix_B.host[j*stride + i] = inputB[i];
      }
    }

    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        cout << matrix_A.host[j*stride + i] << "\n";
        cout << matrix_B.host[j*stride + i] << "\n";
      }
    }

    // -----------------------------------------------------------------------
    // Allocating device-side resources for matrices
    // -----------------------------------------------------------------------

    cl_int err = 0; // OpenCL error code

    // Create OpenCL buffers for the matrices based on allocated memory regions
    // Create buffers with CL_MEM_USE_HOST_PTR to minimize copying and
    // model situation when matrices are hosted by some native library that
    // uses OpenCL to accelerate calculations.

    matrix_A.device = clCreateBuffer(
        oclobjects.context,
        CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
        matrix_memory_size,
        matrix_A.host,
        &err
    );
    SAMPLE_CHECK_ERRORS(err);

    matrix_B.device = clCreateBuffer(
        oclobjects.context,
        CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR,
        matrix_memory_size,
        matrix_B.host,
        &err
    );
    SAMPLE_CHECK_ERRORS(err);

    matrix_C.device = clCreateBuffer(
        oclobjects.context,
        CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR,
        matrix_memory_size,
        matrix_C.host,
        &err
    );
    SAMPLE_CHECK_ERRORS(err);

    //T alpha = rand_uniform_01<T>();
    //T beta = rand_uniform_01<T>();
    cl_float alpha = 1;
    cl_float beta = 1;
    cout << "Using alpha = " << alpha << " and beta = " << beta << "\n";
    cl_int cl_size = static_cast<int>(size);  // kernel requires int value
    cl_int ldabc = static_cast<int>(stride);  // kernel requires int value

    // -----------------------------------------------------------------------
    // Setting kernel arguments
    // -----------------------------------------------------------------------

    err = clSetKernelArg(executable.kernel, 0, sizeof(cl_mem), &matrix_A.device);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 1, sizeof(cl_int), &ldabc);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 2, sizeof(cl_mem), &matrix_B.device);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 3, sizeof(cl_int), &ldabc);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 4, sizeof(cl_mem), &matrix_C.device);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 5, sizeof(cl_int), &ldabc);
    SAMPLE_CHECK_ERRORS(err);
    err = clSetKernelArg(executable.kernel, 6, sizeof(cl_int), &cl_size);
    SAMPLE_CHECK_ERRORS(err);
    //err = clSetKernelArg(executable.kernel, 7, sizeof(T), &alpha);
    //SAMPLE_CHECK_ERRORS(err);
    //err = clSetKernelArg(executable.kernel, 8, sizeof(T), &beta);
    //SAMPLE_CHECK_ERRORS(err);

    // -----------------------------------------------------------------------
    // Define ndrange iteration space: global and local sizes based on
    // parameters obtained from user.

    // Refer to the sample documentation for clarification about
    // how work is devided among work-groups and work-items.
    // -----------------------------------------------------------------------

    size_t global_size[2] = {
        size / cmdparser.tile_size_M.getValue(),
        size / cmdparser.tile_size_N.getValue()
    };

    size_t local_size[2] = {
        cmdparser.tile_group_M.getValue(),
        cmdparser.tile_group_N.getValue()
    };

    // theoretical number of cl_floating point operations (addition and multiplication) for one kernel execution
    // needed for performance calculations (GFLOPS) at every iteration below
    double flops = double(size)*size*(
        size + // multiplications
        size  // additions
        //+ 2      // multiplication by alpha and beta
    );

    // -----------------------------------------------------------------------
    // Loop with the kernel invocation
    // -----------------------------------------------------------------------

    for(int i = 0; i < cmdparser.iterations.getValue(); ++i)
    {
        // Here we start measuring host time for kernel execution
        double start = time_stamp();

        err = clEnqueueNDRangeKernel(
            oclobjects.queue,
            executable.kernel,
            2,
            0,
            global_size,
            local_size,
            0, 0, 0
        );
            //0, 0, 0  //was last row
        SAMPLE_CHECK_ERRORS(err);

        err = clFinish(oclobjects.queue);
        SAMPLE_CHECK_ERRORS(err);

        // It is important to measure end host time after clFinish call
        double end = time_stamp();

        double time = end - start;
        cout << "Host time: " << time << " sec.\n";
        cout << "Host perf: " << flops/time/1e9 << " GFLOPS\n";
        cout.flush();

        if(i == 0)
        {
            cout << "Here" << "\n";
            cout.flush();

            // Validate result for the first iteration only and
            // only if user wants this.
            // Please note, validation procedure cannot be run at
            // futher iterations after the very first iteration,
            // as the results are being accumulated in C matrix
            // every iteration but validation procedures assumes that
            // C initial values are all zeros.

            clEnqueueMapBuffer(
                oclobjects.queue,
                matrix_C.device,
                CL_TRUE,    // blocking map
                CL_MAP_READ,
                0,
                matrix_memory_size,
                0, 0, 0,
                &err
            );
            SAMPLE_CHECK_ERRORS(err);

            // After map call, host-memory area for matrix C is
            // automatically updated with the latest bits from the device
            // So we just use it by original poi,,nter as well as input matrices:
            if(
                !checkValidity(
                    matrix_A.host,
                    matrix_B.host,
                    matrix_C.host,
                    size,
                    stride,
                    cmdparser.kernel_nt.isSet()    // whether B is transposed or not
                )
            )
            {
                throw Error("Validation procedure reported failures");
            }

            cout.flush();

    stride /= sizeof(cl_float);
    for(int x = 0; x < matrixSize; x++){
      for(int y = 0; y < matrixSize; y++){
        cout<<"C "<< matrix_C.host[y*stride+x] << "\n";
        cout.flush();
      }
    }
            err = clEnqueueUnmapMemObject(
                oclobjects.queue,
                matrix_C.device,
                matrix_C.host,
                0, 0, 0
            );
            SAMPLE_CHECK_ERRORS(err);

            

            // Finish here is only required for correct time measurment on the next iteration
            // It does not affect correctness of calculations because you use the in-order OpenCL queue here.
            err = clFinish(oclobjects.queue);
            SAMPLE_CHECK_ERRORS(err);
        }
    }

    stride /= sizeof(cl_float);
    for(int x = 0; x < matrixSize; x++){
      for(int y = 0; y < matrixSize; y++){
        cout<<"C "<< matrix_C.host[y*stride+x] << "\n";
        cout.flush();
      }
    }

    // All resources are deallocated automatically.
}


// Entry point for sample application, command-line parsing,
// generic OpenCL resources allocation and deallocation.
int main (int argc, const char** argv)
{
    try
    {
        // Define and parse command-line arguments.
        CmdParserGEMM cmdparser(argc, argv);
        cmdparser.parse();

        // Immediatly exit if user wanted to see the usage information only.
        if(cmdparser.help.isSet())
        {
            return 0;
        }

        // Create the necessary OpenCL objects up to device queue.
        OpenCLBasic oclobjects(
            cmdparser.platform.getValue(),
            cmdparser.device_type.getValue(),
            cmdparser.device.getValue()
        );

        // Form build options string from given parameters: macros definitions to pass into kernels
        string build_options =
            "-DT=" + cmdparser.arithmetic.getValue() +
            (cmdparser.arithmetic_double.isSet() ? " -DSAMPLE_NEEDS_DOUBLE" : "") +
            " -DTILE_SIZE_M=" + to_str(cmdparser.tile_size_M.getValue()) +
            " -DTILE_GROUP_M=" + to_str(cmdparser.tile_group_M.getValue()) +
            " -DTILE_SIZE_N=" + to_str(cmdparser.tile_size_N.getValue()) +
            " -DTILE_GROUP_N=" + to_str(cmdparser.tile_group_N.getValue()) +
            " -DTILE_SIZE_K=" + to_str(cmdparser.tile_size_K.getValue());

        cout << "Build program options: " << inquotes(build_options) << "\n";
        cout <<"gemm_nn" << "\n";
        cout << build_options << "\n";
        // Build kernel
        OpenCLProgramOneKernel executable(
            oclobjects,
            L"MatrixMultiplication.cl",
            "",
            "gemm_nn",
            build_options
        );
            //"gemm_" + cmdparser.kernel.getValue(),

        // Call gemm with required type of elements
        std::vector<float> A = std::vector<float>(4);
        std::vector<float> B = std::vector<float>(4);
        A[0] = 0;
        A[1] = 1;
        A[2] = 2;
        A[3] = 3;
        B[0] = 0;
        B[1] = 1;
        B[2] = 2;
        B[3] = 3;
        gemm<cl_float>(cmdparser, oclobjects, executable, A, B, 2);
        // All resource deallocations happen in destructors of helper objects.

        return 0;
    }
    catch(const CmdParser::Error& error)
    {
        cerr
            << "[ ERROR ] In command line: " << error.what() << "\n"
            << "Run " << argv[0] << " -h for usage info.\n";
        return 1;
    }
    catch(const Error& error)
    {
        cerr << "[ ERROR ] Sample application specific error: " << error.what() << "\n";
        return 1;
    }
    catch(const exception& error)
    {
        cerr << "[ ERROR ] " << error.what() << "\n";
        return 1;
    }
    catch(...)
    {
        cerr << "[ ERROR ] Unknown/internal error happened.\n";
        return 1;
    }
}
