cmake_minimum_required(VERSION 3.10)

project ( ExternalTestClassesView )

# set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

add_library(EXTERNAL_TEST_CLASSES_VIEW
  "src/ClassificationResult.cpp"
  "src/ClassProbability.cpp"
  "src/Device.cpp"
  "src/Result.cpp"

  "include/ClassificationResult.hpp"
  "include/ClassProbability.hpp"
  "include/Device.hpp"
  "include/Result.hpp"
)
target_include_directories(EXTERNAL_TEST_CLASSES_VIEW PUBLIC "include/")
