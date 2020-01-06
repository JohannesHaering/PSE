cmake_minimum_required(VERSION 3.10)

# set the project name
project(PSE)
enable_testing()

# add the executable
add_library(ResultPackage src/Data.cpp src/StringData.cpp src/MultipleStringData src/ImageData src/MultipleImageData src/VideoData)

