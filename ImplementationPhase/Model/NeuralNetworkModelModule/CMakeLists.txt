cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkPackage C CXX)

add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")

add_library(NETWORKLAYER "src/NetworkLayer.cpp" "include/NetworkLayer.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")

add_library(CONVOLUTIONLAYER "src/ConvolutionLayer.cpp" "include/ConvolutionLayer.hpp")
target_include_directories(CONVOLUTIONLAYER PUBLIC "include/")

add_library(ACTIVATIONLAYER "src/ActivationLayer.cpp" "include/ActivationLayer.hpp")
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")

add_library(POLLINGLAYER "src/PollingLayer.cpp" "include/PollingLayer.hpp")
target_include_directories(POLLINGLAYER PUBLIC "include/")

add_library(LOCALRESPONSENORMALIZATIONLAYER "src/LocalResponseNormalizationLayer.cpp" "include/LocalResponseNormalizationLayer.hpp")
target_include_directories(LOCALRESPONSENORMALIZATIONLAYER PUBLIC "include/")

add_library(DENSELAYER "src/DenseLayer.cpp" "include/DenseLayer.hpp")
target_include_directories(DENSELAYER PUBLIC "include/")

add_library(FLATTENLAYER "src/FlattenLayer.cpp" "include/FlattenLayer.hpp")
target_include_directories(FLATTENLAYER PUBLIC "include/")

add_library(DROPOUTLAYER "src/DropoutLayer.cpp" "include/DropoutLayer.hpp")
target_include_directories(DROPOUTLAYER PUBLIC "include/")

add_library(COLLECTRESULTSLAYER "src/CollectResultsLayer.cpp" "include/CollectResultsLayer.hpp")
target_include_directories(COLLECTRESULTSLAYER PUBLIC "include/")

add_library(OUTPUTSTORAGELAYER "src/OutputStorageLayer.cpp" "include/OutputStorageLayer.hpp")
target_include_directories(OUTPUTSTORAGELAYER PUBLIC "include/")

add_library(INCEPTIONLAYER "src/InceptionLayer.cpp" "include/InceptionLayer.hpp")
target_include_directories(INCEPTIONLAYER PUBLIC "include/")

# add_library(TYPE_ENUMERATIONS_NN "include/LayerType.hpp" "include/Activation.hpp" "include/PollingType.hpp" "include/LRNType.hpp")
# target_include_directories(TYPE_ENUMERATIONS_NN PUBLIC "include/")

# add_library(MATRIX_DEFINE "include/MatrixDefine.hpp")
# target_include_directories(MATRIX_DEFINE PUBLIC "include/")
