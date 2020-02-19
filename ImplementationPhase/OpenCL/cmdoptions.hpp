#ifndef _INTEL_OPENCL_SAMPLE_GEMM_CMDOPTIONS_HPP_
#define _INTEL_OPENCL_SAMPLE_GEMM_CMDOPTIONS_HPP_

#include "oclobject.hpp"
#include "cmdparser.hpp"


// All command-line options for GEMM sample
class CmdParserGEMM : public CmdParserCommon
{
public:
    // For these options description, please refer to the constructor definition.

    CmdOption<size_t> size;
    CmdOption<int> iterations;

    CmdOption<string> arithmetic;
        CmdEnum<string> arithmetic_float;
        CmdEnum<string> arithmetic_double;

    CmdOption<string> kernel;
        CmdEnum<string> kernel_nt;
        CmdEnum<string> kernel_nn;

    CmdOption<bool> validation;

    CmdOption<size_t> tile_size_M;
    CmdOption<size_t> tile_group_M;

    CmdOption<size_t> tile_size_N;
    CmdOption<size_t> tile_group_N;

    CmdOption<size_t> tile_size_K;

    CmdParserGEMM (int argc, const char** argv);
    virtual void parse ();

    // Check if all parameters have correct and consistent
    // values based on device capabilities.
    void validateParameters (
        OpenCLBasic& oclobjects,
        OpenCLProgramOneKernel& executable,
        size_t size_of_element, // size of one element of matrix in bytes
        size_t alignment    // alignment requirements in bytes
    );

private:

    template <typename T>
    void validatePositiveness (const CmdOption<T>& parameter)
    {
        parameter.validate(
            parameter.getValue() > 0,
            "negative or zero value is provided; should be positive"
        );
    }

    size_t estimateMaxMatrixSize (
        OpenCLBasic& oclobjects,
        size_t size_of_element,
        size_t alignment
    );

    void validateTile (
        const CmdOption<size_t>& tile_group,
        const CmdOption<size_t>& tile_size,
        size_t max_group_value
    );
};


#endif  // end of the include guard
