#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"

void NeuralNetworkAdapter::addLayer(NetworkLayer layer) { this->neuralNetwork.addLayer(layer); }

NetworkLayer NeuralNetworkAdapter::getFirstLayer() { return this->neuralNetwork.getFirstLayer(); }

NetworkLayer NeuralNetworkAdapter::getLastLayer() { return this->neuralNetwork.getLastLayer(); }

NetworkLayer NeuralNetworkAdapter::getNextLayer() { return this->neuralNetwork.getNextLayer(); }        

NetworkLayer NeuralNetworkAdapter::getPreviousLayer() { return this->neuralNetwork.getPreviousLayer(); }
