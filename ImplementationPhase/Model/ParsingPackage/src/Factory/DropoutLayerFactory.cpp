#include "DropoutLayerFactory.hpp"
#include "DropoutLayer.hpp"
#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"

NetworkLayer DropoutLayerFactory::buildLayer()
{
    return DropoutLayer(name, inputDimensions, dropoutRate);
}

DropoutLayerFactory DropoutLayerFactory::setDropoutRate(float dropoutRate)
{
    this -> dropoutRate = dropoutRate;
    return *this;
}