#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork() : NeuralNetwork::NeuralNetwork("Default_Network_Name") {}

NeuralNetwork::NeuralNetwork(std::string name) : name(name), layers()
{
  it = layers.begin();
};

void NeuralNetwork::addLayer(NetworkLayer& layer)
{
  layers.push_back(layer);
}

void NeuralNetwork::setName(std::string name)
{
  this->name = name;
}

std::string NeuralNetwork::getName()
{
  return name;
}

NetworkLayer* NeuralNetwork::getFirstLayer()
{
  it = layers.begin();
  return &(*it);
}

NetworkLayer* NeuralNetwork::getLastLayer()
{
  it = layers.end();
  return &*it;
}

NetworkLayer* NeuralNetwork::getNextLayer()
{
  return &*(++it);
}

NetworkLayer* NeuralNetwork::getPreviousLayer()
{
  return &*(--it);
}

NeuralNetwork::~NeuralNetwork()
{
  layers.clear();
}
