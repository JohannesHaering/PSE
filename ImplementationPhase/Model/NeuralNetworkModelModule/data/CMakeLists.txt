cmake_minimum_required(VERSION 3.10)


project(MnistParser)

include(ExternalProject)

#[[
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/external)
set(MNIST_DIR ${CMAKE_CURRENT_BINARY_DIR}/external)


configure_file(CMakeLists.txt.in external/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/external )
if(result)
  message(FATAL_ERROR "CMake step for mnist failed: ${result}")
endif()

include(ExternalProject)
ExternalProject_Add(mnist-parser
  GIT_REPOSITORY    https://github.com/wichtounet/mnist
  GIT_TAG           master
  SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/external"
  BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/external"
  CONFIGURE_COMMAND ""
  #BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

include_directories(${EXTERNAL_INSTALL_LOCATION})

find_package(MNIST REQUIRED)

#]]


add_library(LAYER "Layers/Layer.cpp" "include/Layer.hpp")
target_include_directories(LAYER PUBLIC "include")

add_library(SIZELAYER "Layers/Dense.cpp" "include/Dense.hpp")
target_link_libraries(SIZELAYER PUBLIC LAYER)
target_include_directories(SIZELAYER PUBLIC "include/")


add_library(ACTIVATIONLAYER "ActivationFunctions/ActivationLayer.cpp" "ActivationFunctions/Sigmoid.cpp" "ActivationFunctions/LeakyReLu.cpp" "ActivationFunctions/ReLu.cpp" "ActivationFunctions/Softmax.cpp" "include/ActivationLayer.hpp" "include/Sigmoid.hpp" "include/LeakyReLu.hpp" "include/ReLu.hpp" "include/Softmax") 
target_link_libraries(ACTIVATIONLAYER PUBLIC LAYER)
target_include_directories(ACTIVATIONLAYER PUBLIC "include/")

add_library(TRAINER "Trainer.cpp" "include/Trainer.hpp")
target_include_directories(TRAINER PUBLIC "include/")
target_link_libraries(TRAINER PUBLIC LAYER)


#target_link_libraries(LAYER PUBLIC ACTIVATIONLAYER SIZELAYER)
#add_library(LAYER ACTIVATIONLAYER SIZELAYER)

set(MNIST_DATA_DIR mnist/)
set(EXTERNAL_INSTALL_LOCATION mnist)
add_executable(FirstTest "main.cpp")
#add_dependencies(FirstTest mnist-parser)
target_link_libraries(FirstTest PUBLIC LAYER ACTIVATIONLAYER SIZELAYER TRAINER)
target_include_directories(FirstTest PUBLIC "include/")
target_include_directories(FirstTest PUBLIC "${EXTERNAL_INSTALL_LOCATION}/include/mnist")
target_compile_definitions(FirstTest PRIVATE MNIST_DATA_LOCATION="${MNIST_DATA_DIR}")
