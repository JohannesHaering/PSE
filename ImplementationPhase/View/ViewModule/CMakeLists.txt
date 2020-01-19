cmake_minimum_required(VERSION 3.10)

# set the project name
project(ViewFacadeModule C CXX)

add_library(VIEWFACADE "src/viewfacade.cpp" "include/viewfacade.h")
target_include_directories(VIEWFACADE PUBLIC "include/")

add_library(INFERENCEPAGEADAPTER "src/inferencepageadapter.cpp" "include/inferencepageadapter.h")
target_include_directories(INFERENCEPAGEADAPTER PUBLIC "include/")
target_link_libraries(INFERENCEPAGEADAPTER PUBLIC DEVICE)

add_library(DETECTIONPAGEADAPTER "src/objectdetectioninferencepageadapter.cpp" "include/objectdetectioninferencepageadapter.h")
target_include_directories(DETECTIONPAGEADAPTER PUBLIC "include/")

add_library(CONTENTVIEW "src/contentview.cpp" "include/contentview.h")
target_include_directories(CONTENTVIEW PUBLIC "include/")

