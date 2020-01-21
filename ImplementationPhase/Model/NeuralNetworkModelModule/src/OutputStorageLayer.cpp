#include "OutputStorageLayer.hpp"

OutputStorageLayer::OutputStorageLayer() : NetworkLayer(LayerType::OUTPUT_STORAGE) {}
OutputStorageLayer::OutputStorageLayer(std::string name, MATRIX_3D(float) outputData) : NetworkLayer(LayerType::OUTPUT_STORAGE), outputData(outputData)
{
  this->setName(name);
}

void OutputStorageLayer::setData(MATRIX_3D(float) outputData)
{
  this->outputData = outputData;
}

MATRIX_3D(float) OutputStorageLayer::getData()
{
  return outputData;
}
