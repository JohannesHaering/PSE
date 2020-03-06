cmake_minimum_required(VERSION 3.10)

#add_executable(DataTest "Data_test.cpp")
#target_link_libraries(DataTest PUBLIC DATA)

add_executable(ImageFileIOTest "ImageFileIO_test.cpp")
target_link_libraries(ImageFileIOTest PUBLIC DATA ${OpenCV_LIBS} IO)

add_executable(MultipleImageIOTest "MultipleImageFileIO_test.cpp")
target_link_libraries(MultipleImageIOTest PUBLIC DATA ${OpenCV_LIBS} IO)

add_executable(TextFileIOTest "TextFileIO_test.cpp")
target_link_libraries(TextFileIOTest PUBLIC DATA IO)

add_executable(MultipleTextFileIOTest "MultipleTextFileIO_test.cpp")
target_link_libraries(MultipleTextFileIOTest PUBLIC DATA IO)

add_executable(VideoFileIOTest "VideoFileIO_test.cpp")
target_link_libraries(VideoFileIOTest PUBLIC DATA ${OpenCV_LIBS} IO)

