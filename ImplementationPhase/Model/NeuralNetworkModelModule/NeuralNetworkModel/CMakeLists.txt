cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkModulePackage C CXX)

add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")

add_library(NETWORKLAYER "src/NetworkLayer.cpp" "include/NetworkLayer.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")

add_library(CONVOLUTIONLAYER "src/ConvolutionLayer.cpp" "include/ConvolutionLayer.hpp")
target_include_directories(CONVOLUTIONLAYER PUBLIC "include/")
target_link_libraries(CONVOLUTIONLAYER NETWORKLAYER)

add_library(ACTIVATIONLAYER "src/ActivationLayer.cpp" "include/ActivationLayer.hpp")
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")
target_link_libraries(ACTIVATIONLAYER NETWORKLAYER)

add_library(POLLINGLAYER "src/PollingLayer.cpp" "include/PollingLayer.hpp")
target_include_directories(POLLINGLAYER PUBLIC "include/")
target_link_libraries(POLLINGLAYER NETWORKLAYER)

add_library(LOCALRESPONSENORMALIZATIONLAYER "src/LocalResponseNormalizationLayer.cpp" "include/LocalResponseNormalizationLayer.hpp")
target_include_directories(LOCALRESPONSENORMALIZATIONLAYER PUBLIC "include/")
target_link_libraries(LOCALRESPONSENORMALIZATIONLAYER NETWORKLAYER)

add_library(DENSELAYER "src/DenseLayer.cpp" "include/DenseLayer.hpp")
target_include_directories(DENSELAYER PUBLIC "include/")
target_link_libraries(DENSELAYER NETWORKLAYER)

add_library(FLATTENLAYER "src/FlattenLayer.cpp" "include/FlattenLayer.hpp")
target_include_directories(FLATTENLAYER PUBLIC "include/")
target_link_libraries(FLATTENLAYER NETWORKLAYER)

add_library(DROPOUTLAYER "src/DropoutLayer.cpp" "include/DropoutLayer.hpp")
target_include_directories(DROPOUTLAYER PUBLIC "include/")
target_link_libraries(DROPOUTLAYER NETWORKLAYER)

add_library(COLLECTRESULTSLAYER "src/CollectResultsLayer.cpp" "include/CollectResultsLayer.hpp")
target_include_directories(COLLECTRESULTSLAYER PUBLIC "include/")
target_link_libraries(COLLECTRESULTSLAYER NETWORKLAYER)

add_library(OUTPUTSTORAGELAYER "src/OutputStorageLayer.cpp" "include/OutputStorageLayer.hpp")
target_include_directories(OUTPUTSTORAGELAYER PUBLIC "include/")
target_link_libraries(OUTPUTSTORAGELAYER NETWORKLAYER)

add_library(INCEPTIONLAYER "src/InceptionLayer.cpp" "include/InceptionLayer.hpp")
target_include_directories(INCEPTIONLAYER PUBLIC "include/")
target_link_libraries(INCEPTIONLAYER NETWORKLAYER)

add_library(TYPE_ENUMERATIONS_NN INTERFACE)
target_sources(TYPE_ENUMERATIONS_NN INTERFACE "include/LayerType.hpp" "include/Activation.hpp" "include/PollingType.hpp" "include/LRNType.hpp")

add_library(MATRIX_DEFINE INTERFACE)
target_sources(MATRIX_DEFINE INTERFACE "include/MatrixDefine.hpp")

target_link_libraries(NEURALNETWORK PUBLIC NETWORKLAYER CONVOLUTIONLAYER ACTIVATIONLAYER POLLINGLAYER LOCALRESPONSENORMALIZATIONLAYER DENSELAYER FLATTENLAYER DROPOUTLAYER COLLECTRESULTSLAYER OUTPUTSTORAGELAYER INCEPTIONLAYER)

add_library(SOFTMAXLAYER "src/SoftmaxLayer.cpp" "include/SoftmaxLayer.hpp")
target_include_directories(SOFTMAXLAYER PUBLIC "include/")
target_link_libraries(SOFTMAXLAYER PUBLIC ACTIVATIONLAYER)

add_library(SIGMOIDLAYER "src/SigmoidLayer.cpp" "include/SigmoidLayer.hpp")
target_include_directories(SIGMOIDLAYER PUBLIC "include/")
target_link_libraries(SIGMOIDLAYER PUBLIC ACTIVATIONLAYER)