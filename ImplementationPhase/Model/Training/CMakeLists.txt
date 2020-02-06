cmake_minimum_required(VERSION 3.10)

# set the project name
# project(Training C CXX)

add_library(COMPLETETRAINER "src/CompleteTrainer.cpp" "include/CompleteTrainer.hpp")
target_include_directories(COMPLETETRAINER PUBLIC "include/")
target_link_libraries(COMPLETETRAINER NEURALNETWORKADAPTER)

add_library(TRAINER "src/Trainer.cpp" "include/Trainer.hpp")
target_include_directories(TRAINER PUBLIC "include/")
target_link_libraries(TRAINER NEURALNETWORKADAPTER COMPLETETRAINER CONTROLLERFACADE)

