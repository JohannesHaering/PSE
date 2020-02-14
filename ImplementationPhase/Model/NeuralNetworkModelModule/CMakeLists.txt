cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkModulePackage C CXX)

add_library(LAYERTYPE "include/LayerType.hpp")
target_include_directories(LAYERTYPE PUBLIC "include/")

add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")

add_library(NETWORKLAYER "src/NetworkLayer.cpp" "include/NetworkLayer.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")
target_link_libraries(NETWORKLAYER PUBLIC MATRIX_DEFINE DEVICETYPE)

add_library(ACTIVATIONLAYER "src/ActivationLayer.cpp" "include/ActivationLayer.hpp")
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")
target_link_libraries(ACTIVATIONLAYER PUBLIC NETWORKLAYER)

add_library(DENSELAYER "src/DenseLayer.cpp" "include/DenseLayer.hpp")
target_include_directories(DENSELAYER PUBLIC "include/")
target_link_libraries(DENSELAYER PUBLIC NETWORKLAYER)

target_link_libraries(NEURALNETWORK PUBLIC NETWORKLAYER ACTIVATIONLAYER DENSELAYER LEAKYRELULAYER RELULAYER SIGMOIDLAYER SOFTMAXLAYER)

add_library(SOFTMAXLAYER "src/SoftmaxLayer.cpp" "include/SoftmaxLayer.hpp")
target_include_directories(SOFTMAXLAYER PUBLIC "include/")
target_link_libraries(SOFTMAXLAYER PUBLIC ACTIVATIONLAYER)

add_library(SIGMOIDLAYER "src/SigmoidLayer.cpp" "include/SigmoidLayer.hpp")
target_include_directories(SIGMOIDLAYER PUBLIC "include/")
target_link_libraries(SIGMOIDLAYER PUBLIC ACTIVATIONLAYER)

add_library(LEAKYRELULAYER "src/LeakyReLuLayer.cpp" "include/LeakyReLuLayer.hpp")
target_include_directories(LEAKYRELULAYER PUBLIC "include/")
target_link_libraries(LEAKYRELULAYER PUBLIC ACTIVATIONLAYER)

add_library(RELULAYER "src/ReLuLayer.cpp" "include/ReLuLayer.hpp")
target_include_directories(RELULAYER PUBLIC "include/")
target_link_libraries(RELULAYER PUBLIC ACTIVATIONLAYER)

#add_library(TYPE_ENUMERATIONS_NN INTERFACE)
#target_sources(TYPE_ENUMERATIONS_NN INTERFACE "include/LayerType.hpp" "include/Activation.hpp")

add_library(MATRIX_DEFINE INTERFACE)
target_sources(MATRIX_DEFINE INTERFACE "include/MatrixDefine.hpp")

