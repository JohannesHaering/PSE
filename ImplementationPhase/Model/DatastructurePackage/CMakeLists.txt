cmake_minimum_required(VERSION 3.10)

#project(Datastructures C CXX)

add_library(DETECTIONDATA "src/DetectionData.cpp" "include/DetectionData.hpp" "src/SingleDetectionDataset.cpp" "include/SingleDetectionDataset.hpp")
target_include_directories(DETECTIONDATA PUBLIC "include/")
target_link_libraries(DETECTIONDATA PUBLIC BOUNDINGBOX)
