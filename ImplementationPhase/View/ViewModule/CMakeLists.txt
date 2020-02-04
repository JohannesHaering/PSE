cmake_minimum_required(VERSION 3.10)

project ( ViewModule )

set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

add_library(VIEW_MODULE
  "src/ClassificationResultPanel.cpp"
  "src/ContentView.cpp"
  "src/DetectionControlPanel.cpp"
  "src/DetectionResultPanel.cpp"
  "src/DeviceCheckBoxManager.cpp"
  "src/ImageClassificationControlPanel.cpp"
  "src/InferencePage.cpp"
  "src/InferencePageAdapter.cpp"
  "src/MainWindow.cpp"
  "src/ObjectDetectionInferencePage.cpp"
  "src/ObjectDetectionInferencePageAdapter.cpp"
  "src/TopologyPanel.cpp"
  "src/TrainingPanel.cpp"
  "src/View.cpp"
  "src/ViewFacade.cpp"

  "include/ClassificationResultPanel.hpp"
  "include/ContentView.hpp"
  "include/DetectionControlPanel.hpp"
  "include/DetectionResultPanel.hpp"
  "include/DeviceCheckBoxManager.hpp"
  "include/ImageClassificationControlPanel.hpp"
  "include/InferencePage.hpp"
  "include/InferencePageAdapter.hpp"
  "include/MainWindow.hpp"
  "include/ObjectDetectionInferencePage.hpp"
  "include/ObjectDetectionInferencePageAdapter.hpp"
  "include/TopologyPanel.hpp"
  "include/TrainingPanel.hpp"
  "include/View.hpp"
  "include/ViewFacade.hpp"
)
target_include_directories(VIEW_MODULE PUBLIC "include/")

target_link_libraries(VIEW_MODULE PUBLIC RENDERER_MODULE)
target_link_libraries(VIEW_MODULE PUBLIC EXTERNAL_TEST_CLASSES_VIEW)
target_link_libraries(VIEW_MODULE PUBLIC CONTROLLERFACADE)
target_link_libraries(VIEW_MODULE PUBLIC ${QT5_LIBRARIES} ${OpenCV_LIBS})
