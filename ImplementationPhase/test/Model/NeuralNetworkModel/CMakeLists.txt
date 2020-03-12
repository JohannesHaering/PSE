cmake_minimum_required(VERSION 3.10)

add_executable(ConvolutionTest "ConvolutionLayerTest.cpp")
target_link_libraries(ConvolutionTest PUBLIC CONVOLUTIONLAYER)
target_link_libraries(ConvolutionTest PUBLIC OpenCL::OpenCL)

add_executable(FlattenTest "FlattenLayerTest.cpp")
target_link_libraries(FlattenTest PUBLIC FLATTENLAYER)
target_link_libraries(FlattenTest PUBLIC OpenCL::OpenCL)

add_executable(MaxpoolTest "MaxpoolLayerTest.cpp")
target_link_libraries(MaxpoolTest PUBLIC MAXPOOLLAYER)
target_link_libraries(MaxpoolTest PUBLIC OpenCL::OpenCL)

