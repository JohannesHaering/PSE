#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() : NeuralNetwork("Default_Network_Name") {}

NeuralNetwork::NeuralNetwork(std::string name) : NeuralNetwork(name, 0, 0, 0) {}

NeuralNetwork::NeuralNetwork(std::string name, int width, int height, int channels) : name(name), layers(), width(width), height(height), channels(channels) {
  it = layers.begin();
}

void NeuralNetwork::addLayer(NetworkLayer* layer) {
  layers.push_back(layer);
}

void NeuralNetwork::setName(std::string name) { this->name = name; }

void NeuralNetwork::setInputDimensions(int width, int height, int channels) {
  this->width = width;
  this->height = height;
  this->channels = channels;
}

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
  if(it == layers.end()) return nullptr;
  return *(it++);
}

NetworkLayer* NeuralNetwork::getPreviousLayer() {
  if(--it == layers.begin()) return nullptr;
  return *(it);
}

int NeuralNetwork::NeuralNetwork::getLayerCount() { return layers.size(); }


NeuralNetwork::~NeuralNetwork() {
  layers.clear();
}
