cmake_minimum_required(VERSION 3.10)

# set the project name
#project(Tutorial)
enable_testing()
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIR})

# add the executable
add_library(ResultPackage src/Result.cpp src/ResultManager.cpp )
#add_executable(ResultPackage src/Result.cpp src/ResultManager.cpp )
