cmake_minimum_required(VERSION 3.10)

# set the project name
# project(ModelFacadePackage C CXX)

add_library(MODELFACADE "src/ModelFacade.cpp" "include/ModelFacade.hpp")
target_include_directories(MODELFACADE PUBLIC "include/")

add_library(CLASSIFICATIONDATASETFACADE "src/ClassificationDatasetFacade.cpp" "include/ClassificationDatasetFacade.hpp")
target_include_directories(CLASSIFICATIONDATASETFACADE PUBLIC "include/")
target_link_libraries(CLASSIFICATIONDATASETFACADE PUBLIC IO CLASSIFICATIONRESULT CLASSIFICATIONDATASETPARSER DATA MODELFACADE)

add_library(DETECTIONDATAFACADE "src/DetectionDataFacade.cpp" "include/DetectionDataFacade.hpp")
target_include_directories(DETECTIONDATAFACADE PUBLIC "include/")
target_link_libraries(DETECTIONDATAFACADE PUBLIC IO DETECTIONDATA DETECTIONDATAPARSER DATA MODELFACADE)

add_library(IMAGEFACADE "src/ImageFacade.cpp" "include/ImageFacade.hpp")
target_include_directories(IMAGEFACADE PUBLIC "include/")
target_link_libraries(IMAGEFACADE PUBLIC IO CAMERA IMAGEPARSING DATA VIDEO MODELFACADE)
target_link_libraries(IMAGEFACADE PUBLIC ${OpenCV_LIBS} )

add_library(PARSERESULTFACADE "src/ResultFacade.cpp" "include/ResultFacade.hpp")
target_include_directories(PARSERESULTFACADE PUBLIC "include/")
target_link_libraries(PARSERESULTFACADE PUBLIC DETECTIONRESULT DETECTIONRESULTPARSER IO CLASSIFICATIONRESULT CLASSIFICATIONDATASETPARSER DATA)

#add_library(NEURALNETWORKFACADE "src/NeuralNetworkFacade.cpp" "include/NeuralNetworkFacade.hpp")
#target_include_directories(NEURALNETWORKFACADE PUBLIC "include/")
#target_link_libraries(NEURALNETWORKFACADE PUBLIC NEURALNETWORK IO DATA NEURALNETWORKPARSER)
