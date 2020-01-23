cmake_minimum_required(VERSION 3.10)

# set the project name
project(RendererModule C CXX)

add_library(CLASSIFICATIONRESULTRENDERER "src/classificationresultrenderer.cpp" "include/classificationresultrenderer.h")
target_include_directories(CLASSIFICATIONRESULTRENDERER PUBLIC "include/")

add_library(TRAININGRENDERER "src/trainingrenderer.cpp" "include/trainingrenderer.h")
target_include_directories(TRAININGRENDERER PUBLIC "include/")
