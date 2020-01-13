cmake_minimum_required(VERSION 3.10)

# set the project name
project(EventHandlerModule C CXX)

add_library(POWERPREDICTORFROMFILE "src/PowerPredictorFromFile.cpp" "include/PowerPredictorFromFile.hpp")
target_include_directories(POWERPREDICTORFROMFILE PUBLIC "include/")

add_library(PERFORMANCEPREDICTORFROMFILE "src/PerformancePredictorFromFile.cpp" "include/PerformancePredictorFromFile.hpp")
target_include_directories(PERFORMANCEPREDICTORFROMFILE PUBLIC "include/")