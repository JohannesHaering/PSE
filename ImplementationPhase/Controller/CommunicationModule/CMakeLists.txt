cmake_minimum_required(VERSION 3.10)

add_library(CHANNEL "include/Channel.hpp" "src/Channel.cpp")
target_include_directories(CHANNEL PUBLIC "include/")
