#ifndef ACTIVATION_LAYER_FACTORY
#define ACTIVATION_LAYER_FACTORY

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "ActivationLayer.hpp"

class ActivationLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    ActivationLayerFactory setActivation(float (*activation)(float) a);

private:
    float (*activation)(float);
}:
#endif