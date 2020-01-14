#include "ActivationLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "ActivationLayer.hpp"

NeuralNetworkLayer ActivationLayerFactory::buildLayer()
{
    return ActivationLayer(name, inputDimensions, activation);
}

ActivationLayerFactory ActivationLayerFactory::setActivation(float (*activation)(float))
{
    (*this).activation = activation;
    return *this;
}