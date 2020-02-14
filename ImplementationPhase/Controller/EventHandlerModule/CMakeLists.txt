cmake_minimum_required(VERSION 3.10)

# set the project name
project(EventHandlerModule C CXX)

add_library(EVENTHANDLER "src/EventHandler.cpp" "include/EventHandler.hpp")
target_include_directories(EVENTHANDLER PUBLIC "include/")

add_library(FILEEXPLORERHANDLER "src/FileExplorerHandler.cpp" "include/FileExplorerHandler.hpp")
target_include_directories(FILEEXPLORERHANDLER PUBLIC "include/")
target_link_libraries(FILEEXPLORERHANDLER PUBLIC EVENTHANDLER)
target_link_libraries(FILEEXPLORERHANDLER PUBLIC VIEW_MODULE)

add_library(INPUTIMAGEHANDLER "src/InputImageHandler.cpp" "include/InputImageHandler.hpp" "src/InputImageHandlerTrainer.cpp" "include/InputImageHandlerTrainer.hpp")
target_include_directories(INPUTIMAGEHANDLER PUBLIC "include/")
target_link_libraries(INPUTIMAGEHANDLER PUBLIC FILEEXPLORERHANDLER)
target_link_libraries(INPUTIMAGEHANDLER PUBLIC DISTRIBUTOR)
target_link_libraries(INPUTIMAGEHANDLER PUBLIC VIEW_MODULE)
# target_link_libraries(INPUTIMAGEHANDLER PUBLIC INFERENCEPAGEADAPTER)

add_library(NEURALNETWORKHANDLER "src/NeuralNetworkHandler.cpp" "include/NeuralNetworkHandler.hpp")
target_include_directories(NEURALNETWORKHANDLER PUBLIC "include/")
target_link_libraries(NEURALNETWORKHANDLER PUBLIC FILEEXPLORERHANDLER)
target_link_libraries(NEURALNETWORKHANDLER PUBLIC INFERENCER)
target_link_libraries(NEURALNETWORKHANDLER PUBLIC NEURALNETWORKSETTER)
target_link_libraries(NEURALNETWORKHANDLER PUBLIC VIEW_MODULE)

add_library(NEWRESULTHANDLER "src/NewResultHandler.cpp" "include/NewResultHandler.hpp")
target_include_directories(NEWRESULTHANDLER PUBLIC "include/")
target_link_libraries(NEWRESULTHANDLER PUBLIC INFERENCINGDISTRIBUTOR)
target_link_libraries(NEWRESULTHANDLER PUBLIC NEURALNETWORKPAGER)
target_link_libraries(NEWRESULTHANDLER PUBLIC IMAGEPAGER)
target_link_libraries(NEWRESULTHANDLER PUBLIC SAVERESULTHANDLER)

add_library(NEWTRAINSTEPHANDLER "src/NewTrainStepHandler.cpp" "include/NewTrainStepHandler.hpp")
target_include_directories(NEWTRAINSTEPHANDLER PUBLIC "include/")
target_link_libraries(NEWTRAINSTEPHANDLER PUBLIC VIEW_MODULE)
# target_link_libraries(NEWTRAINSTEPHANDLER PUBLIC TRAININGPAGE)

add_library(NEXTHANDLER "src/NextHandler.cpp" "include/NextHandler.hpp")
target_include_directories(NEXTHANDLER PUBLIC "include/")
target_link_libraries(NEXTHANDLER PUBLIC PAGER INFERENCINGDISTRIBUTORCLASSIFICATION)

add_library(PREVHANDLER "src/PrevHandler.cpp" "include/PrevHandler.hpp")
target_include_directories(PREVHANDLER PUBLIC "include/")
target_link_libraries(PREVHANDLER PUBLIC PAGER INFERENCINGDISTRIBUTORCLASSIFICATION)

add_library(PREDICTIONHANDLER "src/PredictionHandler.cpp" "include/PredictionHandler.hpp")
target_include_directories(PREDICTIONHANDLER PUBLIC "include/")
target_link_libraries(PREDICTIONHANDLER PUBLIC VIEW_MODULE)
target_link_libraries(PREDICTIONHANDLER PUBLIC RESULTMANAGER)
target_link_libraries(PREDICTIONHANDLER PUBLIC DISPATCHMANAGER)
target_link_libraries(PREDICTIONHANDLER PUBLIC POWERPREDICTORFROMFILE)
target_link_libraries(PREDICTIONHANDLER PUBLIC PERFORMANCEPREDICTORFROMFILE)

add_library(SAVERESULTHANDLER "src/SaveResultHandler.cpp" "include/SaveResultHandler.hpp")
target_include_directories(SAVERESULTHANDLER PUBLIC "include/")
target_link_libraries(SAVERESULTHANDLER PUBLIC INFERENCINGDISTRIBUTOR)
target_link_libraries(SAVERESULTHANDLER PUBLIC NEURALNETWORKPAGER)
target_link_libraries(SAVERESULTHANDLER PUBLIC IMAGEPAGER)
target_link_libraries(SAVERESULTHANDLER PUBLIC VIEW_MODULE)

add_library(UPDATERESULTHANDLER "src/UpdateResultHandler.cpp" "include/UpdateResultHandler.hpp")
target_include_directories(UPDATERESULTHANDLER PUBLIC "include/")
target_link_libraries(UPDATERESULTHANDLER PUBLIC SAVERESULTHANDLER)

add_library(STARTHANDLER "src/StartHandler.cpp" "include/StartHandler.hpp")
target_include_directories(STARTHANDLER PUBLIC "include/")
target_link_libraries(STARTHANDLER PUBLIC INFERENCER)
target_link_libraries(STARTHANDLER PUBLIC EVENTHANDLER)

add_library(DEVICEHANDLER "src/DeviceHandler.cpp" "include/DeviceHandler.hpp")
target_include_directories(DEVICEHANDLER PUBLIC "include/")
target_link_libraries(DEVICEHANDLER PUBLIC VIEW_MODULE)
target_link_libraries(DEVICEHANDLER PUBLIC DEVICE)
target_link_libraries(DEVICEHANDLER PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(DEVICEHANDLER PUBLIC RESULTMANAGER)
target_link_libraries(DEVICEHANDLER PUBLIC DISPATCHMANAGER)

# add_library(MAINHANDLER "src/MainHandler.cpp" "include/MainHandler.hpp")
# target_include_directories(MAINHANDLER PUBLIC "include/")
# target_link_libraries(MAINHANDLER PUBLIC CONTROLLERFACADE)
