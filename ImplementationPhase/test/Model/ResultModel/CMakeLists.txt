cmake_minimum_required(VERSION 3.10)

add_library(RESULTMODELTEST "ResultModelTest.hpp")
target_link_libraries(RESULTMODELTEST RESULT)
target_link_libraries(RESULTMODELTEST CLASSPROBABILITY)
target_link_libraries(RESULTMODELTEST CLASSIFICATIONRESULT)
target_link_libraries(RESULTMODELTEST RESULTMANAGER)
#target_link_libraries(DetectionResultTest DETECTIONRESULT RESULT)
#target_link_libraries(BoundingBoxTest BOUNDINGBOX RESULT)
