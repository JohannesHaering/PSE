cmake_minimum_required(VERSION 3.10)

link_libraries(gtest)
link_libraries(gtest_main)

add_subdirectory(Model)
add_subdirectory(View)
add_subdirectory(Controller)

