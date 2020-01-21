cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkAdapterModule C CXX)

add_library(NEURALNETWORKADAPTER "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_include_directories(NEURALNETWORKADAPTER PUBLIC "include/")
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NEURALNETWORK)
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NETWORKLAYER)

