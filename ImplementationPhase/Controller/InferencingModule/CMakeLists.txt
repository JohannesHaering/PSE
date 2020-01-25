cmake_minimum_required(VERSION 3.10)

# set the project name
project(EventHandlerModule C CXX)

add_library(INFERENCER "src/Inferencer.cpp" "include/Inferencer.hpp")
target_include_directories(INFERENCER PUBLIC "include/")
target_link_libraries(INFERENCER PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(INFERENCER PUBLIC IMAGE_CLASSIFICATION_VIEW)

add_library(DISTRIBUTOR "src/Distributor.cpp" "include/Distributor.hpp")
target_include_directories(DISTRIBUTOR PUBLIC "include/")
target_link_libraries(DISTRIBUTOR PUBLIC INFERENCER)

add_library(IMAGEPAGER "src/ImagePager.cpp" "include/ImagePager.hpp")
target_include_directories(IMAGEPAGER PUBLIC "include/")
target_link_libraries(IMAGEPAGER PUBLIC INFERENCER)
target_link_libraries(IMAGEPAGER PUBLIC PAGER)
target_link_libraries(IMAGEPAGER PUBLIC IMAGE_CLASSIFICATION_VIEW)

add_library(INFERENCINGDISTRIBUTOR "src/InferencingDistributor.cpp" "include/InferencingDistributor.hpp")
target_include_directories(INFERENCINGDISTRIBUTOR PUBLIC "include/")
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC DISTRIBUTOR)
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC IMAGE_CLASSIFICATION_VIEW)
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC DISPATCHMANAGER)
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC RESULTMANAGER)
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(INFERENCINGDISTRIBUTOR PUBLIC PARSERESULTFACADE)

add_library(INFERENCINGDISTRIBUTORCLASSIFICATION "src/InferencingDistributorClassification.cpp" "include/InferencingDistributorClassification.hpp")
target_include_directories(INFERENCINGDISTRIBUTORCLASSIFICATION PUBLIC "include/")
target_link_libraries(INFERENCINGDISTRIBUTORCLASSIFICATION PUBLIC INFERENCINGDISTRIBUTOR)

add_library(INFERENCINGDISTRIBUTORDETECTION "src/InferencingDistributorDetection.cpp" "include/InferencingDistributorDetection.hpp")
target_include_directories(INFERENCINGDISTRIBUTORDETECTION PUBLIC "include/")
target_link_libraries(INFERENCINGDISTRIBUTORDETECTION PUBLIC INFERENCINGDISTRIBUTOR)

add_library(NEURALNETWORKPAGER "src/NeuralNetworkPager.cpp" "include/NeuralNetworkPager.hpp")
target_include_directories(NEURALNETWORKPAGER PUBLIC "include/")
target_link_libraries(NEURALNETWORKPAGER PUBLIC PAGER)
target_link_libraries(NEURALNETWORKPAGER PUBLIC IMAGE_CLASSIFICATION_VIEW)

add_library(NEURALNETWORKSETTER "src/NeuralNetworkSetter.cpp" "include/NeuralNetworkSetter.hpp")
target_include_directories(NEURALNETWORKSETTER PUBLIC "include/")
target_link_libraries(NEURALNETWORKSETTER PUBLIC INFERENCER)
target_link_libraries(NEURALNETWORKSETTER PUBLIC NEURALNETWORKFACADE)
target_link_libraries(NEURALNETWORKSETTER PUBLIC NEURALNETWORKADAPTER)

add_library(PAGER "src/Pager.cpp" "include/Pager.hpp")
target_include_directories(PAGER PUBLIC "include/")
target_link_libraries(PAGER PUBLIC IMAGE_CLASSIFICATION_VIEW)
target_link_libraries(PAGER PUBLIC INFERENCINGDISTRIBUTOR)

add_library(TOPOLOGYINFERENCER "src/TopologyInferencer.cpp" "include/TopologyInferencer.hpp")
target_include_directories(TOPOLOGYINFERENCER PUBLIC "include/")
target_link_libraries(TOPOLOGYINFERENCER PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(TOPOLOGYINFERENCER PUBLIC IMAGE_CLASSIFICATION_VIEW)

#add_library(TRAININGDISTRIBUTOR "src/TrainingDistributor.cpp" "include/TrainingDistributor.hpp")
#target_include_directories(TRAININGDISTRIBUTOR PUBLIC "include/")
#target_link_libraries(TRAININGDISTRIBUTOR PUBLIC IMAGE_CLASSIFICATION_VIEW)
#target_link_libraries(TRAININGDISTRIBUTOR PUBLIC DISTRIBUTOR)
#target_link_libraries(TRAININGDISTRIBUTOR PUBLIC TRAINER)
#target_link_libraries(TRAININGDISTRIBUTOR PUBLIC NEURALNETWORKADAPTER)
