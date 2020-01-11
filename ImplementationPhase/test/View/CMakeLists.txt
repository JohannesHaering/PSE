cmake_minimum_required(VERSION 3.10)

add_executable( DisplayImageTest DisplayImage.cpp )
target_link_libraries( DisplayImageTest ${OpenCV_LIBS} )

add_subdirectory(ViewModel)
add_subdirectory(Renderer)
