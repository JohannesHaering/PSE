#include "ActivationLayer.hpp"

ActivationLayer::ActivationLayer() : NetworkLayer(LayerType::ACTIVATION) function::RELU {}

ActivationLayer::ActivationLayer(std::string name, int* inputDimensions, Activation function) : NetworkLayer(name, inputDimensions, LayerType::ACTIVATION), function(function) {}

void ActivationLayer::setFunction(Activation function)
{
  this->function = function;
}

Activation ActivationLayer::getFunction()
{
  return function;
}

int* ActivationLayer::getTensorDimenssions() {
  return new int[1] {0}
}
