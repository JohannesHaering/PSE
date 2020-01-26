cmake_minimum_required(VERSION 3.10)

add_library(CURRENTPERFORMANCEPREDICTOR "include/CurrentPerformancePredictor.hpp" "src/CurrentPerformancePredictor.cpp")
target_include_directories(CURRENTPERFORMANCEPREDICTOR PUBLIC "include/")
target_link_libraries(CURRENTPERFORMANCEPREDICTOR PUBLIC PERFORMANCEPREDICTORFROMFILE)
target_link_libraries(CURRENTPERFORMANCEPREDICTOR PUBLIC CHANNEL IMAGEFACADE NEURALNETWORKFACADE NEURALNETWORKADAPTER)

add_library(PERFORMANCEPREDICTORFROMFILE "include/PerformancePredictorFromFile.hpp" "src/PerformancePredictorFromFile.cpp")
target_include_directories(PERFORMANCEPREDICTORFROMFILE PUBLIC "include/")
target_link_libraries(PERFORMANCEPREDICTORFROMFILE PUBLIC CHANNEL)

add_library(POWERPREDICTORFROMFILE "include/PowerPredictorFromFile.hpp" "src/PowerPredictorFromFile.cpp")
target_include_directories(POWERPREDICTORFROMFILE PUBLIC "include/")
target_link_libraries(POWERPREDICTORFROMFILE PUBLIC CHANNEL)

add_library(PREDICTOR "include/Predictor.hpp" "src/Predictor.cpp")
target_include_directories(PREDICTOR PUBLIC "include/")
