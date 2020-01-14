cmake_minimum_required(VERSION 3.10)

add_executable(INFERENCERTEST "src/InferencerTest.cpp")
target_link_libraries(INFERENCERTEST PUBLIC INFERENCER)
