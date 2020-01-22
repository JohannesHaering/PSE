cmake_minimum_required(VERSION 3.10)

project ( ImageClassification )

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)


#find_package(Qt5 COMPONENTS Widgets Charts REQUIRED)


#find_package(Qt5Core REQUIRED)
#find_package(Qt5Gui REQUIRED)
#find_package(Qt5Charts REQUIRED)
#find_package(Qt5Widgets REQUIRED)

#set(QT5_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

#set(IMAGE_CLASSIFICATION_TARGET ${CMAKE_PROJECT_NAME})
# include(${QT_USE_FILE})

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

include_directories(
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Gui_INCLUDE_DIRS}
  ${Qt5Charts_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ViewModule/include
  RendererModule/include
)

set(IMAGE_CLASSIFICATION_SOURCES
  ViewModule/src/classificationresult.cpp
  ViewModule/src/classificationresultpanel.cpp
  ViewModule/src/classprobability.cpp
  ViewModule/src/contentview.cpp
  ViewModule/src/detectioncontrolpanel.cpp
  ViewModule/src/detectionresultpanel.cpp
  ViewModule/src/device.cpp
  ViewModule/src/devicecheckboxmanager.cpp
  ViewModule/src/imageclassificationcontrolpanel.cpp
  ViewModule/src/inferencepage.cpp
  ViewModule/src/inferencepageadapter.cpp
  ViewModule/src/main.cpp
  ViewModule/src/mainwindow.cpp
  ViewModule/src/objectdetectioninferencepage.cpp
  ViewModule/src/objectdetectioninferencepageadapter.cpp
  ViewModule/src/result.cpp
  ViewModule/src/topology.cpp
  ViewModule/src/training.cpp
  ViewModule/src/view.cpp
  ViewModule/src/viewfacade.cpp
  RendererModule/src/classificationresultrenderer.cpp
  RendererModule/src/detectionresultrenderer.cpp
  RendererModule/src/render.cpp
  RendererModule/src/renderer.cpp
  RendererModule/src/trainingrenderer.cpp
)

set(IMAGE_CLASSIFICATION_HEADERS
  ViewModule/include/classificationresult.h
  ViewModule/include/classificationresultpanel.h
  ViewModule/include/classprobability.h
  ViewModule/include/contentview.h
  ViewModule/include/detectioncontrolpanel.h
  ViewModule/include/detectionresultpanel.h
  ViewModule/include/device.h
  ViewModule/include/devicecheckboxmanager.h
  ViewModule/include/imageclassificationcontrolpanel.h
  ViewModule/include/inferencepage.h
  ViewModule/include/inferencepageadapter.h
  ViewModule/include/mainwindow.h
  ViewModule/include/objectdetectioninferencepage.h
  ViewModule/include/objectdetectioninferencepageadapter.h
  ViewModule/include/result.h
  ViewModule/include/topology.h
  ViewModule/include/training.h
  ViewModule/include/view.h
  ViewModule/include/viewfacade.h
  RendererModule/include/classificationresultrenderer.h
  RendererModule/include/detectionresultrenderer.h
  RendererModule/include/render.h
  RendererModule/include/renderer.h
  RendererModule/include/trainingrenderer.h
)

set(IMAGE_CLASSIFICATION_UIS
  ViewModule/ui/classificationresultpanel.ui
  ViewModule/ui/detectioncontrolpanel.ui
  ViewModule/ui/detectionresultpanel.ui
  ViewModule/ui/devicecheckboxmanager.ui
  ViewModule/ui/imageclassificationcontrolpanel.ui
  ViewModule/ui/inferencepage.ui
  ViewModule/ui/mainwindow.ui
  ViewModule/ui/objectdetectioninferencepage.ui
  ViewModule/ui/topology.ui
  ViewModule/ui/training.ui
  RendererModule/ui/render.ui
)

qt5_wrap_ui(IMAGE_CLASSIFICATION_UI_GENERATED_HEADERS ${IMAGE_CLASSIFICATION_UIS})
QT5_WRAP_CPP(IMAGE_CLASSIFICATION_MOC_HEADERS ${IMAGE_CLASSIFICATION_HEADERS})
# qt5_add_resources(GENERATED_SOURCES ${RESOURCES})
# qt5_wrap_cpp(GENERATED_SOURCES ${HEADERS})

include_directories("${CMAKE_BINARY_DIR}")

# Build the app!
add_executable(
  ${IMAGE_CLASSIFICATION_TARGET}
  ${IMAGE_CLASSIFICATION_SOURCES}
  ${IMAGE_CLASSIFICATION_MOC_HEADERS}
  ${IMAGE_CLASSIFICATION_UIS}
)

# Link the app!
target_link_libraries(${IMAGE_CLASSIFICATION_TARGET} ${QT5_LIBRARIES})
