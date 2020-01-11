cmake_minimum_required(VERSION 3.10)

# set the project name
project(ResultPackageMain C CXX)


add_library(RESULT "src/Result.cpp" "include/Result.hpp")
target_include_directories(RESULT PUBLIC "include/")


add_library(CLASSPROBABILITY "src/ClassProbability.cpp" "include/ClassProbability.hpp")
target_include_directories(CLASSPROBABILITY PUBLIC "include/")


add_library(BOUNDINGBOX "src/BoundingBox.cpp" "include/BoundingBox.hpp")
target_include_directories(BOUNDINGBOX PUBLIC "include/")
#target_link_libraries(BOUNDINGBOX PUBLIC RESULT)#not sure


add_library(CLASSIFICATIONRESULT "src/ClassificationResult.cpp" "include/ClassificationResult.hpp")
target_include_directories(CLASSIFICATIONRESULT PUBLIC "include/")
#target_link_libraries(CLASSIFICATIONRESULT PUBLIC RESULT)#not sure


add_library(DETECTIONRESULT "src/DetectionResult.cpp" "include/DetectionResult.hpp")
target_include_directories(DETECTIONRESULT PUBLIC "include/")
#target_link_libraries(DETECTIONRESULT PUBLIC BOUNDINGBOX)#not sure


add_library(RESULTMANAGER "src/ResultManager.cpp" "include/ResultManager.hpp")
target_include_directories(RESULTMANAGER PUBLIC "include/")
target_link_libraries(RESULTMANAGER PUBLIC RESULT)

add_executable(ResultPackageMain "src/main.cpp")
target_link_libraries(ResultPackageMain PUBLIC RESULTMANAGER)
target_link_libraries(ResultPackageMain PUBLIC CLASSIFICATIONRESULT)
target_link_libraries(ResultPackageMain PUBLIC DETECTIONRESULT)
target_link_libraries(ResultPackageMain PUBLIC BOUNDINGBOX)
target_link_libraries(ResultPackageMain PUBLIC CLASSPROBABILITY)
