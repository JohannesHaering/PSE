cmake_minimum_required(VERSION 3.10)

# set the project name
project(ViewFacadeModule C CXX)

add_library(VIEWFACADE "src/ViewFacade.cpp" "include/ViewFacade.hpp")
target_include_directories(VIEWFACADE PUBLIC "include/")
target_link_libraries(VIEWFACADE PUBLIC RESULT)
target_link_libraries(VIEWFACADE PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(VIEWFACADE PUBLIC DEVICE)

add_library(INFERENCEPAGE "include/InferencePage.hpp")
target_include_directories(INFERENCEPAGE PUBLIC "include/")
target_link_libraries(INFERENCEPAGE PUBLIC RESULT)
