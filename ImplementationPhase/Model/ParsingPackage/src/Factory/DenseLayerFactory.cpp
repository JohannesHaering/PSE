#include "DenseLayerFactory.hpp"
#include "DenseLayer.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

NetworkLayer* DenseLayerFactory::buildLayer()
{   
    DenseLayer* layer = new DenseLayer(inputDimensions, matrix[0].size());
    layer.set_weights(matrix);
    return layer;
}

DenseLayerFactory DenseLayerFactory::setMatrix(std::vector<std::vector<float>> matrix)
{
    this -> matrix = matrix;
    return *this;
}
