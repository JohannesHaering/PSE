#include "NeuralNetworkAdapter.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

NeuralNetworkAdapter::NeuralNetworkAdapter(NeuralNetwork neuralNetwork) : neuralNetwork(neuralNetwork){}
NeuralNetworkAdapter::NeuralNetworkAdapter(){}

void NeuralNetworkAdapter::addLayer(NetworkLayer* layer) { neuralNetwork.addLayer(layer); }
void NeuralNetworkAdapter::setName(std::string name) { neuralNetwork.setName(name); }
void NeuralNetworkAdapter::setLabels(std::list<std::string> labels) { neuralNetwork.setLabels(labels); }
std::string NeuralNetworkAdapter::getName() { return neuralNetwork.getName(); }
int NeuralNetworkAdapter::getWidth() { return neuralNetwork.getWidth(); }
int NeuralNetworkAdapter::getHeight() { return neuralNetwork.getHeight(); }
int NeuralNetworkAdapter::getChannels() { return neuralNetwork.getChannels(); }
std::list<std::string> NeuralNetworkAdapter::getLabels() { return neuralNetwork.getLabels(); }
std::list<NetworkLayer*>::iterator NeuralNetworkAdapter::begin() { return neuralNetwork.begin(); }
std::list<NetworkLayer*>::iterator NeuralNetworkAdapter::end() { return neuralNetwork.end(); }
std::list<NetworkLayer*>::reverse_iterator NeuralNetworkAdapter::rbegin() { return neuralNetwork.rbegin(); }
std::list<NetworkLayer*>::reverse_iterator NeuralNetworkAdapter::rend() { return neuralNetwork.rend(); }
int NeuralNetworkAdapter::getLayerCount() { return neuralNetwork.getLayerCount(); }
NeuralNetwork NeuralNetworkAdapter:: getNeuralNetwork() {  return neuralNetwork; }
