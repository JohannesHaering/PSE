cmake_minimum_required(VERSION 3.10)

# set the project name
project(NeuralNetworkModulePackage C CXX)

set(InferenceEngine_DIR "/opt/intel/openvino/inference_engine/share")
set(Ngraph_DIR "/opt/intel/openvino/deployment_tools/ngraph/cmake")

get_filename_component(CMAKE_PREFIX_PATH "${InferenceEngine_DIR}" ABSOLUTE)

message(STATUS "Looking for inference engine configuration file at: ${CMAKE_PREFIX_PATH}")
find_package(InferenceEngine 1.1)

get_filename_component(CMAKE_PREFIX_PATH "${Ngraph_DIR}" ABSOLUTE)
message(STATUS "Looking for ngraph configuration file at: ${CMAKE_PREFIX_PATH}")
find_package(ngraph)

if (NOT InferenceEngine_FOUND)
    message(FATAL_ERROR "Inference Engine was not found")
endif()

if (NOT ngraph_FOUND)
    message(FATAL_ERROR "Inference Engine was not found")
endif()

add_library(LAYERTYPE "include/LayerType.hpp")
target_include_directories(LAYERTYPE PUBLIC "include/")

add_library(NEURALNETWORK "src/NeuralNetwork.cpp" "include/NeuralNetwork.hpp")
target_include_directories(NEURALNETWORK PUBLIC "include/")
target_link_libraries(NEURALNETWORK PUBLIC MATRIX_DEFINE NETWORKLAYER ACTIVATIONLAYER DENSELAYER LEAKYRELULAYER RELULAYER SIGMOIDLAYER SOFTMAXLAYER MAXPOOLLAYER)

add_library(OPENVINO "src/OpenVino/OpenVino.cpp" "include/OpenVino/OpenVino.hpp")
target_include_directories(OPENVINO PUBLIC "include/OpenVino/")
target_link_libraries(OPENVINO PUBLIC MATRIX_DEFINE "${NGRAPH_LIBRARIES}" "${InferenceEngine_LIBRARIES}")

add_library(NETWORKLAYER "src/NetworkLayer.cpp" "include/NetworkLayer.hpp")
target_include_directories(NETWORKLAYER PUBLIC "include/")
target_link_libraries(NETWORKLAYER PUBLIC MATRIX_DEFINE DEVICETYPE MATRIX_DEFINE)

add_library(CONVOLUTIONLAYER "include/ConvolutionLayer.hpp" "src/ConvolutionLayer.cpp")
target_include_directories(CONVOLUTIONLAYER PUBLIC "include/")
target_link_libraries(CONVOLUTIONLAYER PUBLIC NETWORKLAYER DEVICETYPE MATRIX_DEFINE)

add_library(ACTIVATIONLAYER "include/ActivationLayer.hpp")
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")
target_link_libraries(ACTIVATIONLAYER PUBLIC NETWORKLAYER DEVICETYPE MATRIX_DEFINE)

add_library(MAXPOOLLAYER "src/MaxPoolLayer.cpp" "include/MaxPoolLayer.hpp")
target_include_directories(MAXPOOLLAYER PUBLIC "include/")
target_link_libraries(MAXPOOLLAYER PUBLIC NETWORKLAYER MATRIX_DEFINE MAXPOOLSTRATEGY DEVICETYPE )

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

add_library(DENSELAYERSTRATEGY "include/NetworkLayerStrategies/DenseLayerStrategy.hpp" "src/NetworkLayerStrategies/DenseLayerCPP.cpp" "include/NetworkLayerStrategies/DenseLayerCPP.hpp" "src/NetworkLayerStrategies/DenseLayerASIC.cpp" "include/NetworkLayerStrategies/DenseLayerASIC.hpp")
target_include_directories(DENSELAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(DENSELAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY DENSELAYER MATRIX_DEFINE OPENVINO)

add_library(RELULAYERSTRATEGY "include/NetworkLayerStrategies/ReLuLayerStrategy.hpp" "src/NetworkLayerStrategies/ReLuLayerCPP.cpp" "include/NetworkLayerStrategies/ReLuLayerCPP.hpp" "src/NetworkLayerStrategies/ReLuLayerASIC.cpp" "include/NetworkLayerStrategies/ReLuLayerASIC.hpp")
target_include_directories(RELULAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(RELULAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE OPENVINO)

add_library(LEAKYRELULAYERSTRATEGY "include/NetworkLayerStrategies/LeakyReLuLayerStrategy.hpp" "src/NetworkLayerStrategies/LeakyReLuLayerCPP.cpp" "include/NetworkLayerStrategies/LeakyReLuLayerCPP.hpp"  "src/NetworkLayerStrategies/LeakyReLuLayerASIC.cpp" "include/NetworkLayerStrategies/LeakyReLuLayerASIC.hpp")
target_include_directories(LEAKYRELULAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(LEAKYRELULAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE OPENVINO)

#add_library(LEAKYRELULAUERCPU "src/NetworkLayerStrategies/LeakyReLuLayerCPU.cpp" "include/NetworkLayerStrategies/LeakyReLuLayerCPU.hpp")
#target_include_directories(LEAKYRELULAUERCPU PUBLIC "include/NetworkLayerSrategies")
#target_link_libraries(LEAKYRELULAUERCPU PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE LEAKYRELULAYERSTRATEGY)

#add_library(RELULAYERCPU "src/NetworkLayerStrategies/ReLuLayerCPU.cpp" "include/NetworkLayerStrategies/ReLuLayerCPU.hpp")
#target_include_directories(RELULAYERCPU PUBLIC "include/NetworkLayerSrategies")
#target_link_libraries(RELULAYERCPU PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE RELULAYERSTRATEGY)

#add_library(DENSELAYERCPU "src/NetworkLayerStrategies/DenseLayerCPU.cpp" "include/NetworkLayerStrategies/DenseLayerCPU.hpp")
#target_include_directories(DENSELAYERCPU PUBLIC "include/NetworkLayerSrategies")
#target_link_libraries(DENSELAYERCPU PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE RELULAYERSTRATEGY FUNCTIONALITY)

add_library(SOFTMAXSTRATEGY "include/NetworkLayerStrategies/SoftmaxLayerStrategy.hpp" "src/NetworkLayerStrategies/SoftmaxLayerCPP.cpp" "include/NetworkLayerStrategies/SoftmaxLayerCPP.hpp" "src/NetworkLayerStrategies/SoftmaxLayerASIC.cpp" "include/NetworkLayerStrategies/SoftmaxLayerASIC.hpp" )
target_include_directories(SOFTMAXSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(SOFTMAXSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE OPENVINO)

add_library(MAXPOOLSTRATEGY "include/NetworkLayerStrategies/MaxPoolLayerStrategy.hpp" "include/NetworkLayerStrategies/MaxPoolLayerASIC.hpp" "src/NetworkLayerStrategies/MaxPoolLayerASIC.cpp")
target_include_directories(MAXPOOLSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(MAXPOOLSTRATEGY PUBLIC NETWORKLAYERSTRATEGY DEVICETYPE MATRIX_DEFINE OPENVINO)

add_library(SIGMOIDLAYERSTRATEGY "include/NetworkLayerStrategies/SigmoidLayerStrategy.hpp" "src/NetworkLayerStrategies/SigmoidLayerCPP.cpp" "include/NetworkLayerStrategies/SigmoidLayerCPP.hpp" "src/NetworkLayerStrategies/SigmoidLayerASIC.cpp" "include/NetworkLayerStrategies/SigmoidLayerASIC.hpp" )
target_include_directories(SIGMOIDLAYERSTRATEGY PUBLIC "include/NetworkLayerStrategies")
target_link_libraries(SIGMOIDLAYERSTRATEGY PUBLIC NETWORKLAYERSTRATEGY MATRIX_DEFINE OPENVINO)

#add_library(FUNCTIONALITY "include/NetworkLayerStrategies/MatrixMultiplicationCPU.hpp" "src/NetworkLayerStrategies/MatrixMultiplicationCPU.cpp" "include/NetworkLayerStrategies/VectorAdditionCPU.hpp" "src/NetworkLayerStrategies/VectorAdditionCPU.cpp")
#target_include_directories(FUNCTIONALITY PUBLIC "include/NetworkLayerStrategies")
