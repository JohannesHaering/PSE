cmake_minimum_required(VERSION 3.10)

# set the project name
# project(VideoHandlingPackage C CXX)

add_library(CAMERA "src/CameraHandler.cpp" "include/CameraHandler.hpp")
target_include_directories(CAMERA PUBLIC "include/")
target_link_libraries( CAMERA ${OpenCV_LIBS} )

add_library(VIDEO "src/VideoCutter.cpp" "src/VideoHandler.cpp" "include/VideoCutter.hpp" "include/VideoHandler.hpp")
target_include_directories(VIDEO PUBLIC "include/")
target_link_libraries( VIDEO ${OpenCV_LIBS} )
