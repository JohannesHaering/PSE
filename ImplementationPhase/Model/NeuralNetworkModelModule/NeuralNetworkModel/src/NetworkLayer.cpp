#include "NetworkLayer.hpp"
/*
NetworkLayer::NetworkLayer(std::string name, int* inputDimensions, LayerType layerType) : name(name), layerType(layerType), inputDimensions{inputDimensions[0], inputDimensions[1], inputDimensions[2]} {}

NetworkLayer::NetworkLayer(LayerType layerType) : NetworkLayer("UnnamedLayer", new int[3] {0, 0, 0}, layerType) {}

void NetworkLayer::setName(std::string name) {
  this->name = name;
}

void NetworkLayer::setInputDimensions(int* inputDimensions) {
  if(sizeof(inputDimensions)/sizeof(inputDimensions[0] == 3)) {
    inputDimensions = new int[3] {inputDimensions[0], inputDimensions[1], inputDimensions[2]};
    // this->inputDimensions[0] = inputDimensions[0];
    // this->inputDimensions[1] = inputDimensions[1];
    // this->inputDimensions[2] = inputDimensions[2];
  }
}*/

//std::string NetworkLayer::getName() { return name; }

LayerType NetworkLayer::getLayerType() { return layerType; }

int* NetworkLayer::getInputDimensions() { return inputDimensions; }

//int* NetworkLayer::getTensorDimensions() { return new int[4] {0, 0, 0, 0}; }
