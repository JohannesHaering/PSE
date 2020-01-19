#include "OutputStorageLayer.hpp"

OutputStorageLayer::OutputStorageLayer() : NetworkLayer(LayerType::OUTPUT_STORAGE) {}

OutputStorageLayer::OutputStorageLayer(std::string name, MATRIX_3D(double) outputData) : NetworkLayer(LayerType::OUTPUT_STORAGE), outputData(outputData)
{
  this->setName(name);
}

OutputStorageLayer::OutputStorageLayer(std::string name, MATRIX_3D(double) outputData, int* inputDimensions) :  NetworkLayer(name, inputDimensions, LayerType::OUTPUT_STORAGE), outputData(outputData) {}

void OutputStorageLayer::setData(MATRIX_3D(double) outputData)
{
  this->outputData = outputData;
}

MATRIX_3D(double) OutputStorageLayer::getData()
{
  return outputData;
}
