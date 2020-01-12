cmake_minimum_required(VERSION 3.10)

# set the project name
project(ResultPackage C CXX)

<<<<<<< HEAD:ImplementationPhase/Model/ResultModel/CMakeLists.txt

add_library(RESULT "src/Result.cpp" "include/Result.hpp")
target_include_directories(RESULT PUBLIC "include/")


add_library(CLASSPROBABILITY "src/ClassProbability.cpp" "include/ClassProbability.hpp")
target_include_directories(CLASSPROBABILITY PUBLIC "include/")


=======
add_library(RESULT "src/Result.cpp" "include/Result.hpp")
target_include_directories(RESULT PUBLIC "include/")

add_library(CLASSPROBABILITY "src/ClassProbability.cpp" "include/ClassProbability.hpp")
target_include_directories(CLASSPROBABILITY PUBLIC "include/")

>>>>>>> master:ImplementationPhase/Model/ResultModelModule/CMakeLists.txt
add_library(BOUNDINGBOX "src/BoundingBox.cpp" "include/BoundingBox.hpp")
target_include_directories(BOUNDINGBOX PUBLIC "include/")

add_library(CLASSIFICATIONRESULT "src/ClassificationResult.cpp" "include/ClassificationResult.hpp")
target_include_directories(CLASSIFICATIONRESULT PUBLIC "include/")

<<<<<<< HEAD:ImplementationPhase/Model/ResultModel/CMakeLists.txt

=======
>>>>>>> master:ImplementationPhase/Model/ResultModelModule/CMakeLists.txt
add_library(DETECTIONRESULT "src/DetectionResult.cpp" "include/DetectionResult.hpp")
target_include_directories(DETECTIONRESULT PUBLIC "include/")

add_library(RESULTMANAGER "src/ResultManager.cpp" "include/ResultManager.hpp")
target_include_directories(RESULTMANAGER PUBLIC "include/")
target_link_libraries(RESULTMANAGER PUBLIC RESULT)
