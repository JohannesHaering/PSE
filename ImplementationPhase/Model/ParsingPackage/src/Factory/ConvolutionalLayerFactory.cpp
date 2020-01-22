#include "LayerFactory.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "ConvolutionLayer.hpp"
#include "NetworkLayer.hpp"

#include <vector>

NetworkLayer ConvolutionalLayerFactory::buildLayer()
{
    return ConvolutionLayer(name, inputDimensions, weightTensors, stride, padding);
}

ConvolutionalLayerFactory ConvolutionalLayerFactory::setWeightTensors(std::vector<std::vector<std::vector<std::vector<float>>>> weightTensors)
{
    this -> weightTensors = weightTensors;
    return *this;
}

ConvolutionalLayerFactory ConvolutionalLayerFactory::setStride(int stride)
{
    this -> stride = stride;
    return *this;
}
ConvolutionalLayerFactory ConvolutionalLayerFactory::setPadding(int padding)
{
    this -> padding = padding;
    return *this;
}