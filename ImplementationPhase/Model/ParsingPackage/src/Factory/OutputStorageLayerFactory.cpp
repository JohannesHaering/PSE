#include "OutputStorageLayerFactory.hpp"
#include "OutputStorageLayer.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

NetworkLayer OutputStorageLayerFactory::buildLayer()
{
    return OutputStorageLayer(name, inputDimensions, data);
}

OutputStorageLayerFactory OutputStorageLayerFactory::setData(std::vector<std::vector<std::vector<float>>> data)
{
    this -> data = data;
    return *this;
}
