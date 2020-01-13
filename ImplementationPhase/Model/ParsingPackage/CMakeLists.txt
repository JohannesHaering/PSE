cmake_minimum_required(VERSION 3.10)

# set the project name
# project(ParsingPackage C CXX)

add_library(FACTORY "src/Factory/BoundingBoxFactory.cpp" "include/Factory/BoundingBoxFactory.hpp" "src/Factory/ClassificationResultFactory.cpp" "include/Factory/ClassificationResultFactory.hpp" "src/Factory/ClassProbabilityFactory.cpp" "include/Factory/ClassProbabilityFactory.hpp" "src/Factory/DetectionResultFactory.cpp" "include/Factory/DetectionResultFactory.hpp")
target_include_directories(FACTORY PUBLIC "include/Factory")

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

