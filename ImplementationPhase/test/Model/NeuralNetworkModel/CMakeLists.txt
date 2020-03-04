cmake_minimum_required(VERSION 3.10)

#add_executable(NeuralNetworkTest "NeuralNetwork_test.cpp")
#target_link_libraries(NeuralNetworkTest NEURALNETWORK)

#add_executable(NetworkLayerASICTest "NetworkLayerASIC_test.cpp")
#target_link_libraries(NetworkLayerASICTest NEURALNETWORK)

add_executable(ConvolutionTest "ConvolutionLayerTest.cpp")
target_link_libraries(ConvolutionTest PUBLIC CONVOLUTIONLAYER)
target_link_libraries(ConvolutionTest PUBLIC OpenCL::OpenCL)

add_executable(FlattenTest "FlattenLayerTest.cpp")
target_link_libraries(FlattenTest PUBLIC FLATTENLAYER)
target_link_libraries(FlattenTest PUBLIC OpenCL::OpenCL)

add_executable(MaxpoolTest "MaxpoolLayerTest.cpp")
target_link_libraries(MaxpoolTest PUBLIC MAXPOOLLAYER)
target_link_libraries(MaxpoolTest PUBLIC OpenCL::OpenCL)
