cmake_minimum_required(VERSION 3.10)

add_library(NETWORKLAYER "include/NeuralNetworkAdapter.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")

add_library(NEURALNETWORK  "include/NeuralNetwork.hpp")
target_link_libraries(NEURALNETWORK PUBLIC NETWORKLAYER)
target_include_directories(NEURALNETWORK PUBLIC "include/")
