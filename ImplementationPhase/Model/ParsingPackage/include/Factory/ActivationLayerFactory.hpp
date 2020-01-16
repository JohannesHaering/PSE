#ifndef ACTIVATION_LAYER_FACTORY
#define ACTIVATION_LAYER_FACTORY

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "ActivationLayer.hpp"
#include "Activation.hpp"

class ActivationLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    ActivationLayerFactory setActivation(Activation activation);
    ActivationLayerFactory setAlpha(float alpha);

private:
    Activation activation;
float alpha;
}:
#endif