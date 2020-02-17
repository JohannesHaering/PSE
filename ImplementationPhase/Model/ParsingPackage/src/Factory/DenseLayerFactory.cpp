#include "DenseLayerFactory.hpp"
#include "DenseLayer.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

#include <vector>

NetworkLayer* DenseLayerFactory::buildLayer()
{   
    DenseLayer* layer = new DenseLayer(sizeof(inputDimensions)/sizeof(int), matrix[0].size(), 0.1);
    layer->set_weights(matrix);
	layer->set_bias(bias);
    return layer;
}

DenseLayerFactory DenseLayerFactory::setMatrix(std::vector<std::vector<float>> matrix)
{
    this -> matrix = matrix;
    return *this;
}

DenseLayerFactory DenseLayerFactory::setBiases(std::vector<float> bias) {
    this->bias = bias;
    return *this;
}
