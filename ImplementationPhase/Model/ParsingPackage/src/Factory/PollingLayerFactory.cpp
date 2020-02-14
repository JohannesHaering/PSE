#include "PollingLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingType.hpp"

NetworkLayer* PollingLayerFactory::buildLayer()
{
    PollingLayer* poolingLayer = new PollingLayer();
    poolingLayer->setInputDimension(inputDimensions);
    poolingLayer->setBatchSize(batchSize);
    poolingLayer->setWidth(width);
    poolingLayer->setHeight(height);
    poolingLayer->setZ(z);

    poolingLayer->setSize(size);
    poolingLayer->setStride(stride);
    poolingLayer->setType(type);

    return poolingLayer;
}

PollingLayerFactory* PollingLayerFactory::setType(PollingType type)
{
    this -> type = type;
    return this;
}

PollingLayerFactory* PollingLayerFactory::setSize(int size)
{
    this -> size = size;
    return this;
}

PollingLayerFactory* PollingLayerFactory::setStride(int stride)
{
    this -> stride = stride;
    return this;
}