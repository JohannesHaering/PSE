cmake_minimum_required(VERSION 3.10)

add_executable(NEXTHANDLERTEST "NextHandlerTest.cpp")
target_link_libraries(NEXTHANDLERTEST PUBLIC NEXTHANDLER)

add_executable(PREVHANDLERTEST "PrevHandlerTest.cpp")
target_link_libraries(PREVHANDLERTEST PUBLIC PREVHANDLER)

add_executable(NEWRESULTHANDLERTEST "NewResultHandlerTest.cpp")
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC NEWRESULTHANDLER)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC VIEWFACADE)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC NEURALNETWORKPAGER)
target_link_libraries(NEWRESULTHANDLERTEST PUBLIC IMAGEPAGER)

add_executable(STARTHANDLERTEST "StartHandlerTest.cpp")
target_link_libraries(STARTHANDLERTEST PUBLIC STARTHANDLER)

add_executable(PREDICTIONHANDLERTEST "PredictionHandlerTest.cpp")
target_link_libraries(PREDICTIONHANDLERTEST PUBLIC PREDICTIONHANDLER)


