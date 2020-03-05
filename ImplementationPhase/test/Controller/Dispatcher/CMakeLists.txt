cmake_minimum_required(VERSION 3.10)

add_executable(DispatchManagerTest "DispatchManager_test.cpp")
target_link_libraries(DispatchManagerTest DISPATCHMANAGER MODE)

add_executable(DeviceTest "Device_test.cpp")
target_link_libraries(DeviceTest DEVICE)

add_executable(HighPerformanceModeTest "HighPerformanceMode_test.cpp")
target_link_libraries(HighPerformanceModeTest MODE)
