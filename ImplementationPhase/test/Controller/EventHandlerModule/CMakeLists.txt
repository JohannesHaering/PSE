cmake_minimum_required(VERSION 3.10)

add_library(NEXTHANDLERTEST "NextHandlerTest.cpp")
target_link_libraries(NEXTHANDLERTEST PUBLIC NEXTHANDLER)

add_library(PREVHANDLERTEST "PrevHandlerTest.cpp")
target_link_libraries(PREVHANDLERTEST PUBLIC PREVHANDLER)

add_library(NEWRESULTHANDLERTEST "NewResultHandlerTest.cpp")
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC NEWRESULTHANDLER)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC VIEW_MODULE)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC NEURALNETWORKPAGER)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC IMAGEPAGER)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC VIEW_MODULE)

add_library(STARTHANDLERTEST "StartHandlerTest.cpp")
target_link_libraries(STARTHANDLERTEST PUBLIC STARTHANDLER)
target_link_libraries(STARTHANDLERTEST PUBLIC VIEW_MODULE INFERENCINGDISTRIBUTORCLASSIFICATION)


add_library(PREDICTIONHANDLERTEST "PredictionHandlerTest.cpp")
target_link_libraries(PREDICTIONHANDLERTEST PUBLIC PREDICTIONHANDLER)
target_link_libraries(PREDICTIONHANDLERTEST PUBLIC VIEW_MODULE)

add_library(EVENTHANDLERMODULETESTS "EventHandlerModuleTests.hpp")
target_link_libraries(EVENTHANDLERMODULETESTS PUBLIC NEXTHANDLERTEST)
target_link_libraries(EVENTHANDLERMODULETESTS PUBLIC PREVHANDLERTEST)
target_link_libraries(EVENTHANDLERMODULETESTS PUBLIC NEWRESULTHANDLERTEST)
target_link_libraries(EVENTHANDLERMODULETESTS PUBLIC STARTHANDLERTEST)
target_link_libraries(EVENTHANDLERMODULETESTS PUBLIC PREDICTIONHANDLERTEST)
