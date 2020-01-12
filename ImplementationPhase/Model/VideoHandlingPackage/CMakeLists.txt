cmake_minimum_required(VERSION 3.10)

# set the project name
project(VideoHandlingPackage C CXX)

add_library(CAMERA "src/CameraHandler.cpp" "include/CameraHandler.hpp")
target_include_directories(CAMERA PUBLIC "include/")

add_library(VIDEO "src/VideoCutter.cpp" "src/VideoHandler.cpp" "include/VideoCutter.hpp" "include/VideoHandler.hpp")
target_include_directories(VIDEO PUBLIC "include/")

tagret_link_libraries(VideoHandlingPackage PUBLIC CAMERA)
tagret_link_libraries(VideoHandlingPackage PUBLIC VIDEO)