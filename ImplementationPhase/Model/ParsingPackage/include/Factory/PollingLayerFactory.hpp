#ifndef POOLING_LAYER_FACTORY_H_
#define POOLING_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "PollingLayer.hpp"
#include "PollingType.hpp"

class PollingLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    PollingLayerFactory setType(PoolingType type);
    PollingLayerFactory setSize(int size);
    PollingLayerFactory setStride(int stride);

private:
    PoolingType type;
    int size;
    int stride;
}:
#endif