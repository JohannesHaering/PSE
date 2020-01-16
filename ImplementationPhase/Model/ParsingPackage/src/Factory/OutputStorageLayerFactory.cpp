#include "OutputStorageLayerFactory.hpp"
#include "OutputStorageLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

NeuralNetworkLayer OutputStorageLayerFactory::buildLayer()
{
    return new OutputStorageLayer(name, inputDimensions, data);
}

OutputStorageLayerFactory OutputStorageLayerFactory::setData(std::vector<std::vector<std::vector<float>>> data)
{
    this -> data = data;
    return *this;
}
