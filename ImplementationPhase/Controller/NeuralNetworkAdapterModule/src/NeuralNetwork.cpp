#include <string>
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(){}
NeuralNetwork::NeuralNetwork(std::string name){}

void NeuralNetwork::addLayer(NeuralNetworkLayer layer){}
NeuralNetworkLayer NeuralNetwork::getFirstLayer(){}
NeuralNetworkLayer NeuralNetwork::getLastLayer(){}
NeuralNetworkLayer NeuralNetwork::getNextLayer(){}
NeuralNetworkLayer NeuralNetwork::getPreviousLayer(){}
