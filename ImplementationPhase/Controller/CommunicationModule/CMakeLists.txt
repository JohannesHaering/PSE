cmake_minimum_required(VERSION 3.10)

add_library(CHANNEL "include/Channel.hpp" "src/Channel.cpp" "include/CPUChannel.hpp")
target_include_directories(CHANNEL PUBLIC "include/")
target_link_libraries(CHANNEL PUBLIC NEURALNETWORKADAPTER RESULT DEVICE)
