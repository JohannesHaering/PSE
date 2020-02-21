#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() : NeuralNetwork("Default_Network_Name") {}

NeuralNetwork::NeuralNetwork(std::string name) : NeuralNetwork(name, 0, 0, 0) {}

NeuralNetwork::NeuralNetwork(std::string name, int width, int height, int channels) : name(name), layers(), width(width), height(height), channels(channels) {}

void NeuralNetwork::addLayer(NetworkLayer* layer) {
  layers.push_back(layer);
}

void NeuralNetwork::setName(std::string name) { this->name = name; }


void NeuralNetwork::setLabels(std::list<std::string> labels) {
    this->labels = labels;
}

std::string NeuralNetwork::getName() { return name; }

int NeuralNetwork::getWidth() { return width; }

int NeuralNetwork::getHeight() { return height; }

int NeuralNetwork::getChannels() { return channels; }

std::list<std::string> NeuralNetwork::getLabels() { return labels; }


std::list<NetworkLayer*>::iterator NeuralNetwork::begin() {
  return layers.begin();
}

std::list<NetworkLayer*>::iterator NeuralNetwork::end() {
  return layers.end();
}

std::list<NetworkLayer*>::reverse_iterator NeuralNetwork::rbegin() {
  return layers.rbegin();
}

std::list<NetworkLayer*>::reverse_iterator NeuralNetwork::rend() {
  return layers.rend();
}

int NeuralNetwork::NeuralNetwork::getLayerCount() { return layers.size(); }

void NeuralNetwork::setMode(DeviceType type) {
  for( auto it = layers.begin(); it != layers.end(); it++) {
     (*it)->setMode(type);
  }
}  

NeuralNetwork::~NeuralNetwork() {
  layers.clear();
}
