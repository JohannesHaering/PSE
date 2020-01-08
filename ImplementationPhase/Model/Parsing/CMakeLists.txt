cmake_minimum_required(VERSION 3.10)

# set the project name
project(PSE)
enable_testing()

# add the executable
add_library(ParsingPackage src/Factory/BoundingBoxFactory.cpp src/Factory/ClassificationResultFactory.cpp src/Factory/ClassProbabilityFactory src/Factory/DetectionResultFactory.cpp src/BoundingBoxParser.cpp src/ClassProbabilityParser.cpp src/DetectionResultParser.cpp src/ImageLocationParser.cpp src/LineBreakParser.cpp src/Parser.cpp)