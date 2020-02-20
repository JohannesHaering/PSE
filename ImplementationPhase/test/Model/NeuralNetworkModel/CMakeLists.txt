cmake_minimum_required(VERSION 3.10)

#add_executable(NeuralNetworkTest "NeuralNetwork_test.cpp")
#target_link_libraries(NeuralNetworkTest NEURALNETWORK)

add_executable(NetworkLayerASICTest "NetworkLayerASIC_test.cpp")
target_link_libraries(NetworkLayerASICTest NEURALNETWORK)