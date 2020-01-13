cmake_minimum_required(VERSION 3.10)

# set the project name
# project(ModelFacadePackage C CXX)

add_library(MODELFACADE "src/ModelFacade.cpp" "include/ModelFacade.hpp")
target_include_directories(MODELFACADE PUBLIC "include/")

add_library(CLASSIFICATIONDATASETFACADE "src/ClassificationDatasetFacade.cpp" "include/ClassificationDatasetFacade.hpp")
target_include_directories(CLASSIFICATIONDATASETFACADE PUBLIC "include/")

add_library(DETECTIONDATAFACADE "src/DetectionDataFacade.cpp" "include/DetectionDataFacade.hpp")
target_include_directories(DETECTIONDATAFACADE PUBLIC "include/")

add_library(IMAGEFACADE "src/ImageFacade.cpp" "include/ImageFacade.hpp")
target_include_directories(IMAGEFACADE PUBLIC "include/")

add_library(PARSERESULTFACADE "src/ParseResultFacade.cpp" "include/ParseResultFacade.hpp")
target_include_directories(PARSERESULTFACADE PUBLIC "include/")
