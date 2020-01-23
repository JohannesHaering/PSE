#include "InceptionLayer.hpp"
#include "NeuralNetwork.hpp"

InceptionLayer::InceptionLayer() : NetworkLayer(LayerType::INCEPTION), chains() {
  it = chains.begin();
}

InceptionLayer::InceptionLayer(std::string name, int* inputDimensions) : NetworkLayer(name, inputDimensions, LayerType::INCEPTION), chains() {
  it = chains.begin();
}

InceptionLayer::InceptionLayer(std::string name, int* inputDimensions, NeuralNetwork chain) : NetworkLayer(name, inputDimensions, LayerType::INCEPTION), chains() {
  it = chains.begin();
  addLayerChain(chain);
}

void InceptionLayer::addLayerChain(NeuralNetwork chain) {
  chains.push_back(chain);
}

NeuralNetwork InceptionLayer::getFirstChain() {
  it = chains.begin();
  return *it;
}

NeuralNetwork InceptionLayer::getNextChain() { return *(++it); }
