cmake_minimum_required(VERSION 3.10)

add_library(DEVICE "include/Device.hpp" "src/Device.cpp")
target_include_directories(DEVICE PUBLIC "include/")

add_library(MODE "include/Mode.hpp" "src/Mode.cpp")
target_include_directories(MODE PUBLIC "include/")
targeT_link_libraries(MODE PUBLIC DEVICE)

add_library(DISPATCHMANAGER "include/DispatchManager.hpp" "src/DispatchManager.cpp")
target_include_directories(DISPATCHMANAGER PUBLIC "include/")
targeT_link_libraries(DISPATCHMANAGER PUBLIC DEVICE MODE)
target_link_libraries(DISPATCHMANAGER PUBLIC NEURALNETWORKADAPTER)
