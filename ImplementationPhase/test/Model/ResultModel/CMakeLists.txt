cmake_minimum_required(VERSION 3.10)

add_executable(ResultTest "Result_test.cpp")
target_link_libraries(ResultTest RESULT)

add_executable(ClassProbabilityTest "ClassProbability_test.cpp")
target_link_libraries(ClassProbabilityTest CLASSPROBABILITY)

#add_executable(BoundingBoxTest "BoundingBox_test.cpp")
#target_link_libraries(BoundingBoxTest BOUNDINGBOX RESULT)

add_executable(ClassificationResultTest "ClassificationResult_test.cpp")
target_link_libraries(ClassificationResultTest CLASSIFICATIONRESULT CLASSPROBABILITY RESULT)

#add_executable(DetectionResultTest "DetectionResult_test.cpp")
#target_link_libraries(DetectionResultTest DETECTIONRESULT RESULT)

add_executable(ResultManagerTest "ResultManager_test.cpp")
target_link_libraries(ResultManagerTest RESULTMANAGER RESULT)

#not a unit test example.
#how should we handle them?
#add_executable(ResultPackageMain "main.cpp")
#target_link_libraries(ResultPackageMain PUBLIC RESULTMANAGER)
#target_link_libraries(ResultPackageMain PUBLIC CLASSIFICATIONRESULT)
#target_link_libraries(ResultPackageMain PUBLIC DETECTIONRESULT)
#target_link_libraries(ResultPackageMain PUBLIC BOUNDINGBOX)
#target_link_libraries(ResultPackageMain PUBLIC CLASSPROBABILITY)
