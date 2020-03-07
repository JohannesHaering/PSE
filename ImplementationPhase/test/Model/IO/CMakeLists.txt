cmake_minimum_required(VERSION 3.10)

add_executable(IOPackageTest IOPackageTest.cpp)
target_link_libraries(IOPackageTest PUBLIC ${OpenCV_LIBS})
target_link_libraries(IOPackageTest PUBLIC DATA)
target_link_libraries(IOPackageTest PUBLIC  IO)