#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LRNType.hpp"

NeuralNetworkLayer LocalResponseNormalizationLayerFactory::buildLayer()
{
    return LocalResponseNormalizationLayer(name, inputDimensions, type, depth);
}
LocalResponseNormalizationLayerFactory LocalResponseNormalizationLayerFactory::setType(LRNType type)
{
    (*this).type = type;
    return *this;
}
LocalResponseNormalizationLayerFactory LocalResponseNormalizationLayerFactory::setDepth(int depth)
{
    (*this).depth;
    return *this;
}