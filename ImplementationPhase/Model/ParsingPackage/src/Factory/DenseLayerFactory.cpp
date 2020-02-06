#include "DenseLayerFactory.hpp"
#include "DenseLayer.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

NetworkLayer* DenseLayerFactory::buildLayer()
{
    return new DenseLayer(name, inputDimensions, matrix);
}

DenseLayerFactory DenseLayerFactory::setMatrix(std::vector<std::vector<float>> matrix)
{
    this -> matrix = matrix;
    return *this;
}