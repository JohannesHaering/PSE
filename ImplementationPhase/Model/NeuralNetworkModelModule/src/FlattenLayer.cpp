#include "FlattenLayer.hpp"

FlattenLayer::FlattenLayer() : NetworkLayer(LayerType::FLATTEN) {}
FlattenLayer::FlattenLayer(std::string name, int* inputDimensions) : NetworkLayer(name, inputDimensions, LayerType::FLATTEN) {}
