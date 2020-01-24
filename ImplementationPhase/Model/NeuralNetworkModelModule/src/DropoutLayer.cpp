#include "DropoutLayer.hpp"

DropoutLayer::DropoutLayer() : NetworkLayer(LayerType::DROPOUT), dropoutRate(0.4) {}

DropoutLayer::DropoutLayer(std::string name, int* inputDimensions, float dropoutRate) : NetworkLayer(name, inputDimensions, LayerType::DROPOUT), dropoutRate(dropoutRate) {}

void DropoutLayer::setDropoutRate(float dropoutRate) { this->dropoutRate = dropoutRate; }

float DropoutLayer::getDropoutRate() { return dropoutRate; }
