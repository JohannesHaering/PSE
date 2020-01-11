cmake_minimum_required(VERSION 3.10)


add_library(NETWORKLAYER "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")

add_library(NEURALNETWORK "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_link_libraries(NEURALNETWORK PUBLIC NETWORKLAYER)
target_include_directories(NEURALNETWORK PUBLIC "include/")

add_library(NEURALNETWORKADAPTER "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NETWORKLAYER)
target_include_directories(NEURALNETWORKADAPTER PUBLIC "include/")
