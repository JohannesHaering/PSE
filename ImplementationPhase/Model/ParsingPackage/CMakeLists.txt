cmake_minimum_required(VERSION 3.10)

add_library(FACTORY 
"src/Factory/BoundingBoxFactory.cpp" "include/Factory/BoundingBoxFactory.hpp" 
"src/Factory/ClassificationResultFactory.cpp" "include/Factory/ClassificationResultFactory.hpp" 
"src/Factory/ClassProbabilityFactory.cpp" "include/Factory/ClassProbabilityFactory.hpp" 
"src/Factory/DetectionResultFactory.cpp" "include/Factory/DetectionResultFactory.hpp")
target_include_directories(FACTORY PUBLIC "include/Factory")
target_link_libraries(FACTORY PUBLIC BOUNDINGBOX RESULT CLASSPROBABILITY CLASSIFICATIONRESULT DETECTIONRESULT)

add_library(NEURALNETWORKFACTORY 
"src/Factory/ActivationLayerFactory.cpp" "include/Factory/ActivationLayerFactory.hpp" 
"src/Factory/CollectResultsLayerFactory.cpp" "include/Factory/CollectResultsLayerFactory.hpp" 
"src/Factory/ConvolutionalLayerFactory.cpp" "include/Factory/ConvolutionalLayerFactory.hpp" 
"src/Factory/DenseLayerFactory.cpp" "include/Factory/DenseLayerFactory.hpp" 
"src/Factory/DropoutLayerFactory.cpp" "include/Factory/DropoutLayerFactory.hpp" 
"src/Factory/FlattenLayerFactory.cpp" "include/Factory/FlattenLayerFactory.hpp" 
"src/Factory/InceptionLayerFactory.cpp" "include/Factory/InceptionLayerFactory.hpp" 
"src/Factory/LayerFactory.cpp" "include/Factory/LayerFactory.hpp" 
"src/Factory/LocalResponseNormalizationLayerFactory.cpp" "include/Factory/LocalResponseNormalizationLayerFactory.hpp" 
"src/Factory/NeuralNetworkFactory.cpp" "include/Factory/NeuralNetworkFactory.hpp" 
"src/Factory/OutputStorageLayerFactory.cpp" "include/Factory/OutputStorageLayerFactory.hpp" 
"src/Factory/PollingLayerFactory.cpp" "include/Factory/PollingLayerFactory.hpp")
target_include_directories(NEURALNETWORKFACTORY PUBLIC "include/Factory")
target_link_libraries(NEURALNETWORKFACTORY PUBLIC NEURALNETWORK NETWORKLAYER CONVOLUTIONLAYER ACTIVATIONLAYER POLLINGLAYER LOCALRESPONSENORMALIZATIONLAYER DENSELAYER FLATTENLAYER DROPOUTLAYER COLLECTRESULTSLAYER OUTPUTSTORAGELAYER INCEPTIONLAYER)

add_library(LAYERPARSER 
"src/LayerParsing/ActivationLayerParser.cpp" "include/LayerParsing/ActivationLayerParser.hpp"
"src/LayerParsing/CollectResultsLayerParser.cpp" "include/LayerParsing/CollectResultsLayerParser.hpp"
"src/LayerParsing/ConvolutionalLayerParser.cpp" "include/LayerParsing/ConvolutionalLayerParser.hpp"
"src/LayerParsing/DenseLayerParser.cpp" "include/LayerParsing/DenseLayerParser.hpp"
"src/LayerParsing/DropoutLayerParser.cpp" "include/LayerParsing/DropoutLayerParser.hpp"
"src/LayerParsing/FlattenLayerParser.cpp" "include/LayerParsing/FlattenLayerParser.hpp"
"src/LayerParsing/InceptionLayerParser.cpp" "include/LayerParsing/InceptionLayerParser.hpp"
"src/LayerParsing/LayerParser.cpp" "include/LayerParsing/LayerParser.hpp"
"src/LayerParsing/LayerParserDistribution.cpp" "include/LayerParsing/LayerParserDistribution.hpp"
"src/LayerParsing/LRNLayerParser.cpp" "include/LayerParsing/LRNLayerParser.hpp"
"src/LayerParsing/OutputStorageLayerParser.cpp" "include/LayerParsing/OutputStorageLayerParser.hpp"
"src/LayerParsing/PollingLayerParser.cpp" "include/LayerParsing/PollingLayerParser.hpp")
target_include_directories(LAYERPARSER PUBLIC "include/LayerParsing")
target_link_libraries(LAYERPARSER PUBLIC NEURALNETWORKFACTORY NEURALNETWORK PARSER LINEBREAKPARSER  NEURALNETWORK NETWORKLAYER CONVOLUTIONLAYER ACTIVATIONLAYER POLLINGLAYER LOCALRESPONSENORMALIZATIONLAYER DENSELAYER FLATTENLAYER DROPOUTLAYER COLLECTRESULTSLAYER OUTPUTSTORAGELAYER INCEPTIONLAYER)

add_library(NEURALNETWORKPARSER
"src/NeuralNetworkParser.cpp" "include/NeuralNetworkParser.hpp")
target_include_directories(NEURALNETWORKPARSER PUBLIC "include/")
target_link_libraries(NEURALNETWORKPARSER PUBLIC NEURALNETWORK PARSER LINEBREAKPARSER NEURALNETWORKFACTORY LAYERPARSER)

add_library(BOUNDINGBOXPARSER "src/BoundingBoxParser.cpp" "include/BoundingBoxParser.hpp")
target_include_directories(BOUNDINGBOXPARSER PUBLIC "include/")
target_link_libraries(BOUNDINGBOXPARSER PUBLIC BOUNDINGBOX CLASSPROBABILITY CLASSIFICATIONRESULTPARSER PARSER FACTORY)

add_library(CLASSIFICATIONDATASETPARSER "src/ClassificationDatasetParser.cpp" "include/ClassificationDatasetParser.hpp")
target_include_directories(CLASSIFICATIONDATASETPARSER PUBLIC "include/")
target_link_libraries(CLASSIFICATIONDATASETPARSER PUBLIC CLASSIFICATIONRESULT CLASSPROBABILITY CLASSPROBABILITYPARSER FACTORY PARSER)

add_library(CLASSIFICATIONRESULTPARSER "src/ClassificationResultParser.cpp" "include/ClassificationResultParser.hpp")
target_include_directories(CLASSIFICATIONRESULTPARSER PUBLIC "include/")
target_link_libraries(CLASSIFICATIONRESULTPARSER PUBLIC PARSER FACTORY CLASSIFICATIONRESULT CLASSPROBABILITY CLASSPROBABILITYPARSER)

add_library(CLASSPROBABILITYPARSER "src/ClassProbabilityParser.cpp" "include/ClassProbabilityParser.hpp")
target_include_directories(CLASSPROBABILITYPARSER PUBLIC "include/")
target_link_libraries(CLASSPROBABILITYPARSER PUBLIC PARSER FACTORY CLASSPROBABILITY)

add_library(DETECTIONDATAPARSER "src/DetectionDataParser.cpp" "src/SingleDetectionDatasetParser.cpp" "include/DetectionDataParser.hpp" "include/SingleDetectionDatasetParser.hpp")
target_include_directories(DETECTIONDATAPARSER PUBLIC "include/")
target_link_libraries(DETECTIONDATAPARSER PUBLIC PARSER DETECTIONDATA LINEBREAKPARSER BOUNDINGBOXPARSER)

add_library(DETECTIONRESULTPARSER "src/DetectionResultParser.cpp" "include/DetectionResultParser.hpp")
target_include_directories(DETECTIONRESULTPARSER PUBLIC "include/")
target_link_libraries(DETECTIONRESULTPARSER PUBLIC FACTORY PARSER BOUNDINGBOXPARSER DETECTIONRESULT)

add_library(IMAGEPARSING "src/ImageLocationParser.cpp" "src/ImageParser.cpp" "src/ImageParserWithSizing.cpp" "include/ImageLocationParser.hpp" "include/ImageParser.hpp" "include/ImageParserWithSizing.hpp")
target_include_directories(IMAGEPARSING PUBLIC "include/")
target_link_libraries(IMAGEPARSING PUBLIC PARSER LINEBREAKPARSER ${OpenCV_LIBS})

add_library(PARSER "src/Parser.cpp" "include/Parser.hpp")
target_include_directories(PARSER PUBLIC "include/")

add_library(LINEBREAKPARSER "src/LineBreakParser.cpp" "include/LineBreakParser.hpp")
target_include_directories(LINEBREAKPARSER PUBLIC "include/")
target_link_libraries(LINEBREAKPARSER PUBLIC PARSER)

#add_library(MNISTDATAPARSER "include/MNISTDataParser.hpp" "src/MNISTDataParser.cpp")
#target_include_directories(MNISTDATAPARSER PUBLIC "include/")
#target_link_libraries(MNISTDATAPARSER PUBLIC ${OpenCV_LIBS})

#add_library(EVENNOTEVENPARSER "include/EvenNotEvenParser.hpp" "src/EvenNotEvenParser.cpp")
#target_include_directories(EVENNOTEVENPARSER PUBLIC "include/")
#target_link_libraries(EVENNOTEVENPARSER PUBLIC ${OpenCV_LIBS})

