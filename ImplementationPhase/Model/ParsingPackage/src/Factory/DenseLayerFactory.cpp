#include "DenseLayerFactory.hpp"
#include "DenseLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

NeuralNetworkLayer DenseLayerFactory::buildLayer()
{
    return DenseLayer(name, inputDimensions, matrix);
}

DenseLayerFactory DenseLayerFactory::setMatrix(std::vector<std::vector<float>> matrix)
{
    this -> matrix = matrix;
    return *this;
}