cmake_minimum_required(VERSION 3.10)

# set the project name
project(IOPackage C CXX)

add_library(DATA "src/Data.cpp" "include/Data.hpp")
target_include_directories(DATA PUBLIC "include/")

add_library(IO "src/FileIO.cpp" "include/FileIO.hpp" "src/MultipleTextFileIO.cpp" "include/MultipleTextFileIO" "src/TextFileIO.cpp" "include/TextFileIO.hpp)
target_include_directories(IO PUBLIC "include/")