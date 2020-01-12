cmake_minimum_required(VERSION 3.10)

# set the project name
project(ModelFacade C CXX)

add_library(MODEL "src/Model.cpp" "include/Model.hpp")
target_include_directories(MODEL PUBLIC "include/")
target_link_libraries(MODEL PUBLIC RESULT)
target_link_libraries(MODEL PUBLIC NEURALNETWORKADAPTER)

add_library(RESULT "src/Result.cpp" "include/Result.hpp")
target_include_directories(RESULT PUBLIC "include/")

add_library(RESULTMANAGER "src/ResultManager.cpp" "include/ResultManager.hpp")
target_include_directories(RESULTMANAGER PUBLIC "include/")

add_library(TRAINER "src/Trainer.cpp" "include/Trainer.hpp")
target_include_directories(TRAINER PUBLIC "include/")
target_link_libraries(TRAINER PUBLIC NEURALNETWORKADAPTER)