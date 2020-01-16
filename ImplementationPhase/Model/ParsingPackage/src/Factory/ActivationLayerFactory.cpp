#include "ActivationLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "ActivationLayer.hpp"
#include "Activation.hpp"

NeuralNetworkLayer ActivationLayerFactory::buildLayer()
{
    return ActivationLayer(name, inputDimensions, activation);
}

ActivationLayerFactory ActivationLayerFactory::setActivation(Activation activation)
{
    this -> activation = activation;
    return *this;
}