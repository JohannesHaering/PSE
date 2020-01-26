cmake_minimum_required(VERSION 3.10)

add_library(DEVICE "include/Device.hpp" "src/Device.cpp")
target_include_directories(DEVICE PUBLIC "include/")

add_library(MODE "include/Mode.hpp" "src/Mode.cpp" "include/HighEfficiencyMode.hpp" "src/HighEfficiencyMode.cpp" "include/LowPowerMode.hpp" "src/LowPowerMode.cpp" "include/HighPerformanceMode.hpp" "src/HighPerformanceMode.cpp")
target_include_directories(MODE PUBLIC "include/")
targeT_link_libraries(MODE PUBLIC DEVICE)
target_link_libraries(MODE PUBLIC NEURALNETWORKADAPTER)
target_link_libraries(MODE PUBLIC POWERPREDICTORFROMFILE)


add_library(DISPATCHMANAGER "include/DispatchManager.hpp" "src/DispatchManager.cpp")
target_include_directories(DISPATCHMANAGER PUBLIC "include/")
target_link_libraries(DISPATCHMANAGER PUBLIC CHANNEL)
targeT_link_libraries(DISPATCHMANAGER PUBLIC DEVICE MODE)
target_link_libraries(DISPATCHMANAGER PUBLIC NEURALNETWORKADAPTER)
