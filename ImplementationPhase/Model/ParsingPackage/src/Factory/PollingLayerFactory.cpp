#include "PollingLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingType.hpp"

NeuralNetworkLayer PollingLayerFactory::buildLayer()
{
    return PollingLayer(name, inputDimensions, size, stride, type);
}

PollingLayerFactory PollingLayerFactory::setType(PoolingType type)
{
    this -> type = type;
    return *this;
}

PollingLayerFactory PollingLayerFactory::setSize(int size)
{
    this -> size = size;
    return *this;
}

PollingLayerFactory PollingLayerFactory::setStride(int stride)
{
    this -> stride = stride;
    return *this;
}