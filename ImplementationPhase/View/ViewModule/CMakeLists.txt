cmake_minimum_required(VERSION 3.10)

project ( ViewModule )

set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

add_library(VIEW_MODULE
  "src/classificationresult.cpp"
  "src/classificationresultpanel.cpp"
  "src/classprobability.cpp"
  "src/contentview.cpp"
  "src/detectioncontrolpanel.cpp"
  "src/detectionresultpanel.cpp"
  "src/device.cpp"
  "src/devicecheckboxmanager.cpp"
  "src/imageclassificationcontrolpanel.cpp"
  "src/inferencepage.cpp"
  "src/inferencepageadapter.cpp"
  "src/mainwindow.cpp"
  "src/objectdetectioninferencepage.cpp"
  "src/objectdetectioninferencepageadapter.cpp"
  "src/result.cpp"
  "src/topology.cpp"
  "src/training.cpp"
  "src/view.cpp"
  "src/viewfacade.cpp"
  "include/classificationresult.h"
  "include/classificationresultpanel.h"
  "include/classprobability.h"
  "include/contentview.h"
  "include/detectioncontrolpanel.h"
  "include/detectionresultpanel.h"
  "include/device.h"
  "include/devicecheckboxmanager.h"
  "include/imageclassificationcontrolpanel.h"
  "include/inferencepage.h"
  "include/inferencepageadapter.h"
  "include/mainwindow.h"
  "include/objectdetectioninferencepage.h"
  "include/objectdetectioninferencepageadapter.h"
  "include/result.h"
  "include/topology.h"
  "include/training.h"
  "include/view.h"
  "include/viewfacade.h"
)
target_include_directories(VIEW_MODULE PUBLIC "include/")

target_link_libraries(VIEW_MODULE PUBLIC RENDERER_MODULE)
