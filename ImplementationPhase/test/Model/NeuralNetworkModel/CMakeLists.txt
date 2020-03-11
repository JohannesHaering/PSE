cmake_minimum_required(VERSION 3.10)

add_library(ConvolutionTest "ConvolutionLayerTest.cpp")
target_link_libraries(ConvolutionTest PUBLIC CONVOLUTIONLAYER)
target_link_libraries(ConvolutionTest PUBLIC OpenCL::OpenCL)

add_library(FlattenTest "FlattenLayerTest.cpp")
target_link_libraries(FlattenTest PUBLIC FLATTENLAYER)
target_link_libraries(FlattenTest PUBLIC OpenCL::OpenCL)

add_library(MaxpoolTest "MaxpoolLayerTest.cpp")
target_link_libraries(MaxpoolTest PUBLIC MAXPOOLLAYER)
target_link_libraries(MaxpoolTest PUBLIC OpenCL::OpenCL)

