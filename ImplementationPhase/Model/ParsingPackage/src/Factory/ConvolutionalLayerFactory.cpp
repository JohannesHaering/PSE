#include "LayerFactory.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "ConvolutionalLayer.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

NeuralNetworkLayer ConvolutionalLayerFactory::buildLayer()
{
    return ConvolutionalLayer(name, inputDimensions, weightTensors, stride, padding);
}

ConvolutionalLayerFactory ConvolutionalLayerFactory::setWeightTensors(std::vector<std::vector<std::vector<int>>> weightTensors)
{
    (*this).weightTensors = weightTensors;
    return *this;
}

PoolingLayConvolutionalLayerFactoryerFactory ConvolutionalLayerFactory::setStride(int stride)
{
    (*this).stride = stride return this;
    return *this;
}
ConvolutionalLayerFactory ConvolutionalLayerFactory::setPadding(int padding)
{
    (*this).padding = padding;
    return *this;
}