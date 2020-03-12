cmake_minimum_required(VERSION 3.10)

add_library(DEVICE "include/Device.hpp" "src/Device.cpp")
target_include_directories(DEVICE PUBLIC "include/")

add_library(MODE "include/Mode.hpp" "src/Mode.cpp" "include/HighEfficiencyMode.hpp" "src/HighEfficiencyMode.cpp" "include/LowPowerMode.hpp" "src/LowPowerMode.cpp" "include/HighPerformanceMode.hpp" "src/HighPerformanceMode.cpp")
target_include_directories(MODE PUBLIC "include/")
targeT_link_libraries(MODE PUBLIC DEVICE)
target_link_libraries(MODE PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(MODE PUBLIC POWERPREDICTORFROMFILE)
target_link_libraries(MODE PUBLIC IMAGEFACADE)

add_library(DEVICETYPE "include/DeviceType.hpp")
target_include_directories(DEVICETYPE PUBLIC "include/")


add_library(DISPATCHMANAGER "include/DispatchManager.hpp" "src/DispatchManager.cpp")
target_include_directories(DISPATCHMANAGER PUBLIC "include/")
targeT_link_libraries(DISPATCHMANAGER PUBLIC DEVICE MODE DEVICETYPE)
target_link_libraries(DISPATCHMANAGER PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(DISPATCHMANAGER PUBLIC OpenCL::OpenCL)
target_link_libraries(DISPATCHMANAGER PUBLIC CLASSIFICATIONRESULT)
target_link_libraries(DISPATCHMANAGER PUBLIC EXECUTOR MATRIX_DEFINE)
target_link_libraries(DISPATCHMANAGER PUBLIC MNISTDATAPARSER)


add_library(EXECUTOR "include/Executor.hpp" "src/Executor.cpp")
target_include_directories(EXECUTOR PUBLIC "include/")
target_link_libraries(EXECUTOR NEURALNETWORKADAPTER CONTROLLERFACADE MATRIX_DEFINE)
