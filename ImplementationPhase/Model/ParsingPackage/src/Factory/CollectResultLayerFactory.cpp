#include "CollectResultLayerFactory.hpp"
#include "CollectResultLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

NeuralNetworkLayer CollectResultLayerFactory::buildLayer()
{
    return CollectResultLayer(name, inputDimensions);
}