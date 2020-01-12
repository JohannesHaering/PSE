cmake_minimum_required(VERSION 3.10)

# set the project name
project(PredictionModule C CXX)

add_library(CURRENTPERFORMANCEPREDICTOR "src/CurrentPerformancePredictor.cpp" "include/CurrentPerformancePredictor.hpp")
target_include_directories(CURRENTPERFORMANCEPREDICTOR PUBLIC "include/")

add_library(PERFORMANCEPREDICTORFROMFILE "src/PerformancePredictorFromFile.cpp" "include/PerformancePredictorFromFile.hpp")
target_include_directories(PERFORMANCEPREDICTORFROMFILE PUBLIC "include/")

add_library(POWERPREDICTORFROMFILE "src/PowerPredictorFromFile.cpp" "include/PowerPredictorFromFile.hpp")
target_include_directories(POWERPREDICTORFROMFILE PUBLIC "include/")

add_library(PREDICTOR "src/Predictor.cpp" "include/Predictor.hpp")
target_include_directories(PREDICTOR PUBLIC "include/")


target_link_libraries(PredictionModule PUBLIC CURRENTPERFORMANCEPREDICTOR)
target_link_libraries(PredictionModule PUBLIC PERFORMANCEPREDICTORFROMFILE)
target_link_libraries(PredictionModule PUBLIC POWERPREDICTORFROMFILE)
target_link_libraries(PredictionModule PUBLIC PREDICTOR)