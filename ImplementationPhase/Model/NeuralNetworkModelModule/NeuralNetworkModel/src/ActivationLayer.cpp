#include "ActivationLayer.hpp"

ActivationLayer::ActivationLayer() : NetworkLayer(LayerType::ACTIVATION), function(Activation::RELU), alpha(0) {}

ActivationLayer::ActivationLayer(std::string name, int* inputDimensions, Activation function) : NetworkLayer(name, inputDimensions, LayerType::ACTIVATION), function(function), alpha(0) {}

ActivationLayer::ActivationLayer(std::string name, int* inputDimensions, Activation function, float alpha) : NetworkLayer(name, inputDimensions, LayerType::ACTIVATION), function(function), alpha(alpha) {}

void ActivationLayer::setFunction(Activation function) { this->function = function; }

void ActivationLayer::setAlpha(float alpha) { this->alpha = alpha; }

Activation ActivationLayer::getFunction() { return function; }

float ActivationLayer::getAlpha() { return alpha; }
