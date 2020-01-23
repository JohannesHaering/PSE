#include "LocalResponseNormalizationLayer.hpp"

LocalResponseNormalizationLayer::LocalResponseNormalizationLayer() : NetworkLayer(LayerType::LRN), type(LRNType::INTER_CHANNEL), depth(2) {}
LocalResponseNormalizationLayer::LocalResponseNormalizationLayer(std::string name, int* inputDimensions, LRNType type, int depth) : NetworkLayer(name, inputDimensions, LayerType::LRN), type(type), depth(depth) {}

void LocalResponseNormalizationLayer::setType(LRNType type)
{
  this->depth = depth;
}

void LocalResponseNormalizationLayer::setDepth(int depth)
{
  this->depth = depth;
}

LRNType LocalResponseNormalizationLayer::getType()
{
  return type;
}

int LocalResponseNormalizationLayer::getDepth()
{
  return depth;
}
