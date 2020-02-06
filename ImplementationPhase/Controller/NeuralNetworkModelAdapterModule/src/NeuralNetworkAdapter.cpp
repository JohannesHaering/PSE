#include "NeuralNetworkAdapter.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

NeuralNetworkAdapter::NeuralNetworkAdapter(NeuralNetwork neuralNetwork) : neuralNetwork(neuralNetwork){}

void NeuralNetworkAdapter::addLayer(NetworkLayer *layer) { neuralNetwork.addLayer(layer); }

NetworkLayer *NeuralNetworkAdapter::getFirstLayer() { return neuralNetwork.getFirstLayer(); }

NetworkLayer *NeuralNetworkAdapter::getLastLayer() { return neuralNetwork.getLastLayer(); }

NetworkLayer *NeuralNetworkAdapter::getNextLayer() { return neuralNetwork.getNextLayer(); }

NetworkLayer *NeuralNetworkAdapter::getPreviousLayer() { return neuralNetwork.getPreviousLayer(); }

std::string NeuralNetworkAdapter::getName() { return neuralNetwork.getName(); }

int NeuralNetworkAdapter::getLayerCount() { return neuralNetwork.getLayerCount(); }

int NeuralNetworkAdapter::getWidth() { return neuralNetwork.getWidth(); }

int NeuralNetworkAdapter::getHeight() { return neuralNetwork.getHeight(); }

int NeuralNetworkAdapter::getChannels() { return neuralNetwork.getChannels(); }
