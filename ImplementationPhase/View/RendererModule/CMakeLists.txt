cmake_minimum_required(VERSION 3.10)

project ( RendererModule )

set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

add_library(RENDERER_MODULE
  "src/ClassificationResultRenderer.cpp"
  "src/DetectionResultRenderer.cpp"
  "src/Renderer.cpp"
  "src/RenderPanel.cpp"
  "src/TrainingRenderer.cpp"

  "include/ClassificationResultRenderer.hpp"
  "include/DetectionResultRenderer.hpp"
  "include/Renderer.hpp"
  "include/RenderPanel.hpp"
  "include/TrainingRenderer.hpp"
)
target_include_directories(RENDERER_MODULE PUBLIC "include/")

target_link_libraries(RENDERER_MODULE PUBLIC VIEW_MODULE)
target_link_libraries(RENDERER_MODULE PUBLIC RESULT CLASSPROBABILITY BOUNDINGBOX CLASSIFICATIONRESULT DETECTIONRESULT)
# target_link_libraries(RENDERER_MODULE PUBLIC CONTROLLERFACADE)
target_link_libraries(RENDERER_MODULE PUBLIC ${QT5_LIBRARIES} ${OpenCV_LIBS})
