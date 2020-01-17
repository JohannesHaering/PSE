cmake_minimum_required(VERSION 3.10)

add_library(RESULTMANAGERADAPTER "src/ResultManagerAdapter.cpp" "include/ResultManagerAdapter.hpp")
target_include_directories(RESULTMANAGERADAPTER  PUBLIC "include/")
target_link_libraries(RESULTMANAGERADAPTER PUBLIC RESULTMANAGER)
