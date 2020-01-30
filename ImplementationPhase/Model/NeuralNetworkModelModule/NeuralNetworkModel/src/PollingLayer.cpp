#include "PollingLayer.hpp"

PollingLayer::PollingLayer() : NetworkLayer(LayerType::POLLING), size(0), stride(0), type(PollingType::MAX) {}

PollingLayer::PollingLayer(std::string name, int* inputDimensions, int size, int stride, PollingType type) : NetworkLayer(name, inputDimensions, LayerType::POLLING), size(size), stride(stride), type(type) {}

void PollingLayer::setType(PollingType type) { this->type = type; }

void PollingLayer::setSize(int size) { this->size = size; }

void PollingLayer::setStride(int stride) { this->stride = stride; }

PollingType PollingLayer::getType() { return type; }

int PollingLayer::getSize() { return size; }

int PollingLayer::getStride() { return stride; }

int* PollingLayer::getTensorDimensions() { return new int[4] {size, size, 0, 0}; }
