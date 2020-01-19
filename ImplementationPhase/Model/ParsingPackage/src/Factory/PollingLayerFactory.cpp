#include "PollingLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingType.hpp"

NetworkLayer PollingLayerFactory::buildLayer()
{
    return PollingLayer(name, inputDimensions, size, stride, type);
}

PollingLayerFactory PollingLayerFactory::setType(PollingType type)
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