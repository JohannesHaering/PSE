cmake_minimum_required(VERSION 3.10)

find_package(OpenCL REQUIRED)

add_library(AOCL "common/inc/AOCLUtils/aocl_utils.h" "common/inc/AOCLUtils/opencl.h" "common/inc/AOCLUtils/scoped_ptrs.h"  "common/src/AOCLUtils/opencl.cpp")
target_include_directories(AOCL PUBLIC "common/inc/AOCLUtils")
target_link_libraries(AOCL PUBLIC OpenCL::OpenCL)

add_library(MATRIXMULTIPLICATION "matrix_mult/host/inc/MatrixMultiplication.hpp" "matrix_mult/host/inc/matrixMult.h" "matrix_mult/host/src/matrixMult.cpp")
target_include_directories(MATRIXMULTIPLICATION PUBLIC "matrix_mult/host/inc")
target_link_libraries(MATRIXMULTIPLICATION PUBLIC OpenCL::OpenCL)
target_link_libraries(MATRIXMULTIPLICATION PUBLIC AOCL)

#add_executable(main "matrix_mult/host/src/matrixMult.cpp")
#target_link_libraries(main MATRIXMULTIPLICATION AOCL)
