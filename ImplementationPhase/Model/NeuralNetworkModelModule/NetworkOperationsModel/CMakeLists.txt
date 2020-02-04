cmake_minimum_required(VERSION 3.10)

# set the project name
project(NetworkOperationsModulePackage C CXX)

add_library(NETWORKOPERATIONS "src/NetworkOperations.cpp" "include/NetworkOperations.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")
# target_link_libraries(NETWORKOPERATIONS PUBLIC MATRIX_DEFINE)
# target_link_libraries(NETWORKOPERATIONS PUBLIC TYPE_ENUMERATIONS_NN)
target_link_libraries(NETWORKOPERATIONS PUBLIC NEURALNETWORK)


add_library(LAYERCODE "src/LayerCode.cpp" "include/LayerCode.hpp")
target_include_directories(LAYERCODE PUBLIC "include/")
target_link_libraries(LAYERCODE PUBLIC NEURALNETWORK)

target_link_libraries(NETWORKOPERATIONS PUBLIC LAYERCODE)
