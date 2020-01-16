#include <string>
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(){}
NeuralNetwork::NeuralNetwork(std::string name){}

void NeuralNetwork::addLayer(NeuralNetworkLayer layer){}
NeuralNetworkLayer NeuralNetwork::getFirstLayer() { return NeuralNetworkLayer(); }
NeuralNetworkLayer NeuralNetwork::getLastLayer(){ return NeuralNetworkLayer(); }
NeuralNetworkLayer NeuralNetwork::getNextLayer(){ return NeuralNetworkLayer(); }
NeuralNetworkLayer NeuralNetwork::getPreviousLayer(){ return NeuralNetworkLayer(); }
