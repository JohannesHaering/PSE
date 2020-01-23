cmake_minimum_required(VERSION 3.10)

project ( RendererModule )

set(CMAKE_AUTOUIC_SEARCH_PATHS "ui/")

add_library(RENDERER_MODULE
  "src/classificationresultrenderer.cpp"
  "src/detectionresultrenderer.cpp"
  "src/render.cpp"
  "src/renderer.cpp"
  "src/trainingrenderer.cpp"
  "include/classificationresultrenderer.h"
  "include/detectionresultrenderer.h"
  "include/render.h"
  "include/renderer.h"
  "include/trainingrenderer.h"
)
target_include_directories(RENDERER_MODULE PUBLIC "include/")
target_link_libraries(RENDERER_MODULE PUBLIC VIEW_MODULE)
