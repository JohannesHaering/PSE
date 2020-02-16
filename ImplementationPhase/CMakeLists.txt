cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Require OpenCV. if not configured for now, add # before next 2 lines
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )



set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)
find_package(OpenCL REQUIRED)

set(QT5_LIBRARIES Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

set(IMAGE_CLASSIFICATION_TARGET ${CMAKE_PROJECT_NAME})

include_directories(
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Gui_INCLUDE_DIRS}
  ${Qt5Charts_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
)

add_subdirectory(Model)
add_subdirectory(Controller)
add_subdirectory(View)
#add_subdirectory(test)

add_executable(${IMAGE_CLASSIFICATION_TARGET} "View/src/main.cpp")
target_link_libraries(${IMAGE_CLASSIFICATION_TARGET} VIEW_MODULE)
