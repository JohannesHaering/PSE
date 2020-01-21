#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() : NeuralNetwork("Default_Network_Name") {}

NeuralNetwork::NeuralNetwork(std::string name) : NeuralNetwork(name, 0, 0, 0) {}

NeuralNetwork::NeuralNetwork(std::string name, int width, int heigth, int channelNumb) : name(name), layers(), width(width), heigth(heigth), channelNumb(channelNumb) {
  it = layers.begin();
}

void NeuralNetwork::addLayer(NetworkLayer* layer) {
  layers.push_back(layer);
}

void NeuralNetwork::setName(std::string name) { this->name = name; }

void NeuralNetwork::setInputDimensions(int width, int heigth, int channelNumb) {
  this->width = width;
  this->heigth = heigth;
  this->channelNumb = channelNumb;
}

std::string NeuralNetwork::getName() { return name; }

int NeuralNetwork::getWidth() { return width; }

int NeuralNetwork::getHeigth() { return heigth; }

int NeuralNetwork::getChannelNumb() { return channelNumb; }

NetworkLayer* NeuralNetwork::getFirstLayer() {
  it = layers.begin();
  if(layers.size() == 0) return nullptr;
  return *(it++);
}

NetworkLayer* NeuralNetwork::getLastLayer() {
  if(layers.size() == 0) return nullptr;
  it = layers.end();
  return *(--it);
}

NetworkLayer* NeuralNetwork::getNextLayer() {
  if(++it == layers.end()) return nullptr;
  return *it;
}

NetworkLayer* NeuralNetwork::getPreviousLayer() {
  if(--it == layers.begin()) return nullptr;
  return *it;
}

int NeuralNetwork::NeuralNetwork::getLayerCount() { return layers.size(); }


NeuralNetwork::~NeuralNetwork() {
  layers.clear();
}
