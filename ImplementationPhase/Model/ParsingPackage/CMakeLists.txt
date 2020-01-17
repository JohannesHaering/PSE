cmake_minimum_required(VERSION 3.10)

# set the project name
# project(ParsingPackage C CXX)

add_library(FACTORY 
"src/Factory/BoundingBoxFactory.cpp" "include/Factory/BoundingBoxFactory.hpp" 
"src/Factory/ClassificationResultFactory.cpp" "include/Factory/ClassificationResultFactory.hpp" 
"src/Factory/ClassProbabilityFactory.cpp" "include/Factory/ClassProbabilityFactory.hpp" 
"src/Factory/DetectionResultFactory.cpp" "include/Factory/DetectionResultFactory.hpp")
target_include_directories(FACTORY PUBLIC "include/Factory")

add_library(NEURALNETWORKFACTORY 
"src/Factory/ActivationLayerFactory.cpp" "include/Factory/ActivationLayerFactory.hpp" 
"src/Factory/CollectResultLayerFactory.cpp" "include/Factory/CollectResultLayerFactory.hpp" 
"src/Factory/ConvolutionalLayerFactory.cpp" "include/Factory/ConvolutionalLayerFactory.hpp" 
"src/Factory/DenseLayerFactory.cpp" "include/Factory/DenseLayerFactory.hpp" 
"src/Factory/DropoutLayerFactory.cpp" "include/Factory/DropoutLayerFactory.hpp" 
"src/Factory/FlattenLayerFactory.cpp" "include/Factory/FlattenLayerFactory.hpp" 
"src/Factory/InceptionLayerFactory.cpp" "include/Factory/InceptionLayerFactory.hpp" 
"src/Factory/LayerFactory.cpp" "include/Factory/LayerFactory.hpp" 
"src/Factory/LocalResponseNormalizationLayerFactory.cpp" "include/Factory/LocalResponseNormalizationLayerFactory.hpp" 
"src/Factory/NeuralNetworkFactory.cpp" "include/Factory/NeuralNetworkFactorys.hpp" 
"src/Factory/OutputStorageLayerFactory.cpp" "include/Factory/OutputStorageLayerFactory.hpp" 
"src/Factory/PollingLayerFactory.cpp" "include/Factory/PollingLayerFactory.hpp")
target_include_directories(NEURALNETWORKFACTORY PUBLIC "include/Factory")

add_library(LAYERPARSER 
"src/LayerParsing/ActivationLayerParser.cpp" "include/LayerParsing/ActivationLayerParser.hpp"
"src/LayerParsing/CollectResultLayerFactory.cpp" "include/LayerParsing/CollectResultLayerFactory.hpp"
"src/LayerParsing/ConvolutionalLayerParser.cpp" "include/LayerParsing/ConvolutionalLayerFactory.hpp"
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

add_library(NEURALNETWORKPARSER
"src/NeuralNetworkParser.cpp" "include/NeuralNetworkParser.hpp")
target_include_directories(NEURALNETWORKPARSER PUBLIC "include/")

add_library(BOUNDINGBOXPARSER "src/BoundingBoxParser.cpp" "include/BoundingBoxParser.hpp")
target_include_directories(BOUNDINGBOXPARSER PUBLIC "include/")

add_library(CLASSIFICATIONDATASETPARSER "src/ClassificationDatasetParser.cpp" "include/ClassificationDatasetParser.hpp")
target_include_directories(CLASSIFICATIONDATASETPARSER PUBLIC "include/")

add_library(CLASSIFICATIONRESULTPARSER "src/ClassificationResultParser.cpp" "include/ClassificationResultParser.hpp")
target_include_directories(CLASSIFICATIONRESULTPARSER PUBLIC "include/")

add_library(CLASSPROBABILITYPARSER "src/ClassProbabilityParser.cpp" "include/ClassProbabilityParser.hpp")
target_include_directories(CLASSPROBABILITYPARSER PUBLIC "include/")

add_library(DETECTIONDATAPARSER "src/DetectionDataParser.cpp" "src/SingleDetectionDatasetParser.cpp" "include/DetectionDataParser.hpp" "include/SingleDetectionDatasetParser.hpp")
target_include_directories(DETECTIONDATAPARSER PUBLIC "include/")

add_library(DETECTIONRESULTPARSER "src/DetectionResultParser.cpp" "include/DetectionResultParser.hpp")
target_include_directories(DETECTIONRESULTPARSER PUBLIC "include/")

add_library(IMAGEPARSING "src/ImageLocationParser.cpp" "src/ImageParser.cpp" "src/ImageParserWithSizing.cpp" "include/ImageLocationParser.hpp" "include/ImageParser.hpp" "include/ImageParserWithSizing.hpp")
target_include_directories(IMAGEPARSING PUBLIC "include/")

add_library(PARSER "src/Parser.cpp" "include/Parser.hpp")
target_include_directories(PARSER PUBLIC "include/")

add_library(LINEBREAKPARSER "src/LineBreakParser.cpp" "include/LineBreakParser.hpp")
target_include_directories(LINEBREAKPARSER PUBLIC "include/")

