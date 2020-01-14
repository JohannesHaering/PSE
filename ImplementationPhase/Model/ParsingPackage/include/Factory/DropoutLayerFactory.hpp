#ifndef DROPOUT_LAYER_FACTORY
#define DROPOUT_LAYER_FACTORY

#include "NeuralNetworkLayer.hpp"
#include "LayerFactory.hpp"

class DropoutLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    DropoutLayerFactory setDropoutRate(float dropoutRate);

private:
    float dropoutRate;
};
#endif