cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkModulePackage C CXX)

add_library(LAYERTYPE "include/LayerType.hpp")
target_include_directories(LAYERTYPE PUBLIC "include/")

add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")
target_link_libraries(NEURALNETWORK PUBLIC MATRIX_DEFINE NETWORKLAYER ACTIVATIONLAYER DENSELAYER LEAKYRELULAYER RELULAYER SIGMOIDLAYER SOFTMAXLAYER MAXPOOLLAYER)

add_library(NETWORKLAYER "src/NetworkLayer.cpp" "include/NetworkLayer.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")
target_link_libraries(NETWORKLAYER PUBLIC MATRIX_DEFINE DEVICETYPE MATRIX_DEFINE)

add_library(CONVOLUTIONLAYER "include/ConvolutionLayer.hpp" "src/ConvolutionLayer.cpp")
target_include_directories(CONVOLUTIONLAYER PUBLIC "/include")
target_link_libraries(CONVOLUTIONLAYER PUBLIC NETWORKLAYER DEVICETYPE MATRIX_DEFINE)

add_library(ACTIVATIONLAYER "include/ActivationLayer.hpp")
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")
target_link_libraries(ACTIVATIONLAYER PUBLIC NETWORKLAYER DEVICETYPE MATRIX_DEFINE)

add_library(MAXPOOLLAYER "src/MaxPoolLayer.cpp" "include/MaxPoolLayer.hpp")
target_include_directories(MAXPOOLLAYER PUBLIC "include/")
target_link_libraries(MAXPOOLLAYER PUBLIC NETWORKLAYER MATRIX_DEFINE DEVICETYPE)

add_library(DENSELAYER "src/DenseLayer.cpp" "include/DenseLayer.hpp")
target_include_directories(DENSELAYER PUBLIC "include/")
target_link_libraries(DENSELAYER PUBLIC NETWORKLAYER DENSELAYERSTRATEGY DEVICETYPE MATRIX_DEFINE)

add_library(SOFTMAXLAYER "src/SoftmaxLayer.cpp" "include/SoftmaxLayer.hpp")
target_include_directories(SOFTMAXLAYER PUBLIC "include/")
target_link_libraries(SOFTMAXLAYER PUBLIC ACTIVATIONLAYER SOFTMAXSTRATEGY DEVICETYPE MATRIX_DEFINE)

add_library(SIGMOIDLAYER "src/SigmoidLayer.cpp" "include/SigmoidLayer.hpp")
target_include_directories(SIGMOIDLAYER PUBLIC "include/")
target_link_libraries(SIGMOIDLAYER PUBLIC ACTIVATIONLAYER SIGMOIDLAYERSTRATEGY DEVICETYPE MATRIX_DEFINE)

add_library(LEAKYRELULAYER "src/LeakyReLuLayer.cpp" "include/LeakyReLuLayer.hpp")
target_include_directories(LEAKYRELULAYER PUBLIC "include/")
target_link_libraries(LEAKYRELULAYER PUBLIC ACTIVATIONLAYER LEAKYRELULAYERSTRATEGY DEVICETYPE MATRIX_DEFINE)

add_library(RELULAYER "src/ReLuLayer.cpp" "include/ReLuLayer.hpp")
target_include_directories(RELULAYER PUBLIC "include/")
target_link_libraries(RELULAYER PUBLIC ACTIVATIONLAYER RELULAYERSTRATEGY DEVICETYPE)

add_library(TYPE_ENUMERATIONS_NN INTERFACE)
target_sources(TYPE_ENUMERATIONS_NN INTERFACE "include/LayerType.hpp" "include/Activation.hpp")

add_library(MATRIX_DEFINE "include/MatrixDefine.hpp")
target_include_directories(MATRIX_DEFINE PUBLIC "include/")

add_library(NETWORKLAYERSTRATEGY "include/NetworkLayerStrategies/NetworkLayerStrategy.hpp")
target_include_directories(NETWORKLAYERSTRATEGY PUBLIC "include/" )
target_link_libraries(NETWORKLAYERSTRATEGY PUBLIC MATRIX_DEFINE)

add_library(DENSELAYERSTRATEGY "include/NetworkLayerStrategies/DenseLayerStrategy.hpp" "src/NetworkLayerStrategies/DenseLayerCPP.cpp" "include/NetworkLayerStrategies/DenseLayerCPP.hpp" "src/NetworkLayerStrategies/DenseLayerCPU.cpp" "include/NetworkLayerStrategies/DenseLayerCPU.hpp")
target_include_directories(DENSELAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(DENSELAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY DENSELAYER MATRIX_DEFINE FUNCTIONALITY)

add_library(RELULAYERSTRATEGY "include/NetworkLayerStrategies/ReLuLayerStrategy.hpp" "src/NetworkLayerStrategies/ReLuLayerCPP.cpp" "include/NetworkLayerStrategies/ReLuLayerCPP.hpp" "src/NetworkLayerStrategies/ReluLayerCPU.cpp" "include/NetworkLayerStrategies/ReluLayerCPU.hpp")
target_include_directories(RELULAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(RELULAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE)

add_library(LEAKYRELULAYERSTRATEGY "include/NetworkLayerStrategies/LeakyReLuLayerStrategy.hpp" "src/NetworkLayerStrategies/LeakyReLuLayerCPP.cpp" "include/NetworkLayerStrategies/LeakyReLuLayerCPP.hpp" "src/NetworkLayerStrategies/LeakyReluLayerCPU.cpp" "include/NetworkLayerStrategies/LeakyReluLayerCPU.hpp")
target_include_directories(LEAKYRELULAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(LEAKYRELULAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE)

add_library(SOFTMAXSTRATEGY "include/NetworkLayerStrategies/SoftmaxLayerStrategy.hpp" "src/NetworkLayerStrategies/SoftmaxLayerCPP.cpp" "include/NetworkLayerStrategies/SoftmaxLayerCPP.hpp")
target_include_directories(SOFTMAXSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(SOFTMAXSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE)

add_library(SIGMOIDLAYERSTRATEGY "include/NetworkLayerStrategies/SigmoidLayerStrategy.hpp" "src/NetworkLayerStrategies/SigmoidLayerCPP.cpp" "include/NetworkLayerStrategies/SigmoidLayerCPP.hpp")
target_include_directories(SIGMOIDLAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(SIGMOIDLAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE)

add_library(FUNCTIONALITY "include/NetworkLayerStrategies/MatrixMultiplicationCPU.hpp" "src/NetworkLayerStrategies/MatrixMultiplicationCPU.cpp" 
"include/NetworkLayerStrategies/VectorAdditionCPU.hpp" "src/NetworkLayerStrategies/VectorAdditionCPU.cpp")
