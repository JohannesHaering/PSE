cmake_minimum_required(VERSION 3.10)

add_library(NEURALNETWORKADAPTER "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_include_directories(NEURALNETWORKADAPTER PUBLIC "include/")
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NETWORKLAYER)
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NEURALNETWORK)
