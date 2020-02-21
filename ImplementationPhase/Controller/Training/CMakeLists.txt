cmake_minimum_required(VERSION 3.10)

# set the project name
# project(Training C CXX)

add_library(COMPLETETRAINER "src/CompleteTrainer.cpp" "include/CompleteTrainer.hpp")
target_include_directories(COMPLETETRAINER PUBLIC "include/")
target_link_libraries(COMPLETETRAINER PUBLIC NEURALNETWORKADAPTER NETWORKLAYER LAYERTYPE MATRIX_DEFINE)

add_library(TRAINER "src/Trainer.cpp" "include/Trainer.hpp")
target_include_directories(TRAINER PUBLIC "include/")
target_link_libraries(TRAINER PUBLIC NEURALNETWORKADAPTER COMPLETETRAINER MATRIX_DEFINE CONTROLLERFACADE NEURALNETWORKFACADE DATASUPPLY)

add_library(DATASUPPLY 
"src/TrainerDataSupply.cpp" "include/TrainerDataSupply.hpp"
"src/TrainerClassificationDataSupply.cpp" "include/TrainerClassificationDataSupply.hpp"
"include/DataType.hpp")
target_link_libraries(DATASUPPLY PUBLIC RESULT MODELFACADE MNISTDATAPARSER EVENNOTEVENPARSER IMAGEFACADE MATRIX_DEFINE)
target_include_directories(DATASUPPLY PUBLIC "include/")

