cmake_minimum_required(VERSION 3.10)

#add_executable(NeuralNetworkTest "NeuralNetwork_test.cpp")
#target_link_libraries(NeuralNetworkTest NEURALNETWORK)

#add_executable(NetworkLayerASICTest "NetworkLayerASIC_test.cpp")
#target_link_libraries(NetworkLayerASICTest NEURALNETWORK)

add_executable(ConvolutionTest "ConvolutionLayerTest.cpp")
target_link_libraries(ConvolutionTest CONVOLUTIONLAYER)

add_executable(FlattenTest "FlattenLayerTest.cpp")
target_link_libraries(FlattenTest FLATTENLAYER)

add_executable(MaxpoolTest "MaxpoolLayerTest.cpp")
target_link_libraries(MaxpoolTest MAXPOOLLAYER)