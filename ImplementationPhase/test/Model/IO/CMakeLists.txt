cmake_minimum_required(VERSION 3.10)

add_executable(DataTest "Data_test.cpp")
add_executable(IOTest "ImageFileIO_test.cpp" "MultipleImageIO_test.cpp" "TextFileIO_test.cpp" "MultipleTextFileIO_test.cpp" "VideoFileIO_test.cpp")
target_link_libraries(DataTest PUBLIC DATA)
target_link_libraries(IOTest PUBLIC IO)

