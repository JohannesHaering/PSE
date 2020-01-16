#include "DropoutLayerFactory.hpp"
#include "DropoutLayer.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerFactory.hpp"

NeuralNetworkLayer DropoutLayerFactory::buildLayer()
{
    return DropoutLayer(name, inputDimensions, dropoutRate);
}

DropoutLayerFactory DropoutLayerFactory::setDropoutRate(float dropoutRate)
{
    this -> dropoutRate = dropoutRate;
    return *this;
}