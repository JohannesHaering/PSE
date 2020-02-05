#include "ActivationLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "ActivationLayer.hpp"
#include "Activation.hpp"

NetworkLayer* ActivationLayerFactory::buildLayer()
{
    return new ActivationLayer(name, inputDimensions, activation);
}

ActivationLayerFactory ActivationLayerFactory::setActivation(Activation activation)
{
    this -> activation = activation;
    return *this;
}

ActivationLayerFactory ActivationLayerFactory::setAlpha(float alpha)
{
    this -> alpha = alpha;
    return *this;
}
