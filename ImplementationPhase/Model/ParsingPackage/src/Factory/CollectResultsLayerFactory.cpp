#include "CollectResultLayerFactory.hpp"
#include "CollectResultLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

NeuralNetworkLayer CollectResultsLayerFactory::buildLayer()
{
    return CollectResultLayer(name, inputDimensions);
}