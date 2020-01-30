cmake_minimum_required(VERSION 3.10)

# set the project name
project(NetworkOperationsModulePackage C CXX)

add_library(NETWORKOPERATIONS "src/NetworkOperations.cpp" "include/NetworkOperations.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")
target_link_libraries(NETWORKOPERATIONS PUBLIC MATRIX_DEFINE)
