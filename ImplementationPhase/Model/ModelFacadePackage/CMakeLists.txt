cmake_minimum_required(VERSION 3.10)

# set the project name
# project(ModelFacadePackage C CXX)

add_library(MODELFACADE "src/ModelFacade.cpp" "include/ModelFacade.hpp")
target_include_directories(MODELFACADE PUBLIC "include/")

add_library(CLASSIFICATIONDATASETFACADE "src/ClassificationDatasetFacade.cpp" "include/ClassificationDatasetFacade.hpp")
target_include_directories(CLASSIFICATIONDATASETFACADE PUBLIC "include/")
target_link_libraries(CLASSIFICATIONDATASETFACADE PUBLIC IO CLASSIFICATIONRESULT CLASSIFICATIONDATASETPARSER)

add_library(DETECTIONDATAFACADE "src/DetectionDataFacade.cpp" "include/DetectionDataFacade.hpp")
target_include_directories(DETECTIONDATAFACADE PUBLIC "include/")
target_link_libraries(DETECTIONDATAFACADE PUBLIC IO DETECTIONDATA DETECTIONDATAPARSER)

add_library(IMAGEFACADE "src/ImageFacade.cpp" "include/ImageFacade.hpp")
target_include_directories(IMAGEFACADE PUBLIC "include/")
target_link_libraries(IMAGEFACADE PUBLIC IO CAMERA IMAGEPARSER DATA)

add_library(PARSERESULTFACADE "src/ResultFacade.cpp" "include/ResultFacade.hpp")
target_include_directories(PARSERESULTFACADE PUBLIC "include/")
target_link_libraries(PARSERESULTFACADE PUBLIC DETECTIONRESULT DETECTIONRESULTPARSER IO CLASSIFICATIONRESULT CLASSIFICATIONDATASETPARSER DATA)
