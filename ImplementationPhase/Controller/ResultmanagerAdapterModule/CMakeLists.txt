cmake_minimum_required(VERSION 3.10)

# set the project name
project(ResultmanagerAdapterModule C CXX)

add_library(RESULTMANAGERADAPTER "src/ResultmanagerAdapter.cpp" "include/ResultmanagerAdapter.hpp")
target_include_directories(RESULTMANAGERADAPTER  PUBLIC "include/")
target_link_libraries(RESULTMANAGERADAPTER PUBLIC RESULTMANAGER)