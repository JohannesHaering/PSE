cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkAdapterModule C CXX)

add_library(NEURALNETWORKADAPTER "src/NeuralNetworkAdapter.cpp" "include/NeuralNetworkAdapter.hpp")
target_include_directories(NEURALNETWORKADAPTER PUBLIC "include/")
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NEURALNETWORK)
target_link_libraries(NEURALNETWORKADAPTER PUBLIC NEURALNETWORKLAYER)

#add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
#target_include_directories(NEURALNETWORK PUBLIC "include/")
#target_link_libraries(NEURALNETWORK PUBLIC NEURALNETWORKLAYER)

#add_library(NEURALNETWORKLAYER "src/NeuralNetworkLayer.cpp" "include/NeuralNetworkLayer.hpp")
#target_include_directories(NEURALNETWORKLAYER PUBLIC "include/")

