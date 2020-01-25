cmake_minimum_required(VERSION 3.10)

project ( ImageClassification )

find_package(Qt5Charts REQUIRED)
find_package(Qt5Widgets REQUIRED)
# find_package(Qt5Core REQUIRED) # added as dependency for Qt5Widgets
# find_package(Qt5Gui REQUIRED) # added as dependency for Qt5Widgets
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)

set(IMAGE_CLASSIFICATION_TARGET ${CMAKE_PROJECT_NAME})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Name the QT5 libraries
set(QT5_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)


include_directories(
  # ${Qt5Core_INCLUDE_DIRS} # included as dependency with ${Qt5Widgets_INCLUDE_DIRS}
  # ${Qt5Gui_INCLUDE_DIRS} # included as dependency with ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5Charts_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ViewModule/include
  RendererModule/include
)

add_subdirectory(ViewModule)
add_subdirectory(RendererModule)

# Link view and renderer libraries here
add_library(IMAGE_CLASSIFICATION_VIEW INTERFACE)
target_link_libraries(IMAGE_CLASSIFICATION_VIEW INTERFACE VIEW_MODULE RENDERER_MODULE)

# include_directories("${CMAKE_BINARY_DIR}")

# Link the app!
target_link_libraries(IMAGE_CLASSIFICATION_VIEW INTERFACE ${QT5_LIBRARIES} ${OpenCV_LIBS})

# Build the app! (just a main function to test; would prbably moved to Controller)
add_executable(${IMAGE_CLASSIFICATION_TARGET} "src/main.cpp")
target_link_libraries(${IMAGE_CLASSIFICATION_TARGET} IMAGE_CLASSIFICATION_VIEW)
