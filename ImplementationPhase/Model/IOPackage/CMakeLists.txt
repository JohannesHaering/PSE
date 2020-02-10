cmake_minimum_required(VERSION 3.10)

add_library(DATA "src/Data.cpp" "include/Data.hpp")
target_include_directories(DATA PUBLIC "include/")

add_library(IO "src/FileIO.cpp" "include/FileIO.hpp" "src/MultipleTextFileIO.cpp" "include/MultipleTextFileIO.hpp" "src/TextFileIO.cpp" "include/TextFileIO.hpp" "src/ImageFileIO.cpp" "include/ImageFileIO.hpp" "src/MultipleImageFileIO.cpp" "include/MultipleImageFileIO.hpp" "src/VideoFileIO.cpp" "include/VideoFileIO.hpp")
target_include_directories(IO PUBLIC "include/")
#target_link_libraries(IO ${OpenCV_LIBS})
target_link_libraries(IO PUBLIC DATA ${OpenCV_LIBS})
