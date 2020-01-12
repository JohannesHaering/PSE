cmake_minimum_required(VERSION 3.10)

# set the project name
project(ViewFacadeModule C CXX)

add_library(VIEWFACADE "src/ViewFacade.cpp" "include/ViewFacade.hpp")
target_include_directories(VIEWFACADE PUBLIC "include/")
target_link_libraries(VIEWFACADE PUBLIC RESULT)
target_link_libraries(VIEWFACADE PUBLIC NEURALNETWORKADAPTER)