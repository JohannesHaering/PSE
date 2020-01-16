cmake_minimum_required(VERSION 3.10)

# set the project name
project(DispatcherModule C CXX)

add_library(DISPATCHMANAGER "include/DispatchManager.hpp")
target_include_directories(DISPATCHMANAGER PUBLIC "include/")
target_link_libraries(DISPATCHMANAGER PUBLIC MODE)
target_link_libraries(DISPATCHMANAGER PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(DISPATCHMANAGER PUBLIC DEVICE)

add_library(DEVICE "include/Device.hpp" "src/Device.cpp")
target_include_directories(DEVICE PUBLIC "include/")