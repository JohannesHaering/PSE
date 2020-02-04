#include "CollectResultsLayerFactory.hpp"
#include "CollectResultsLayer.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

NetworkLayer CollectResultsLayerFactory::buildLayer()
{
    return CollectResultsLayer(name, inputDimensions);
}