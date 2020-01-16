#ifndef CONVOLUTIONAL_LAYER_FACTORY_H_
#define CONVOLUTIONAL_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <vector>

class ConvolutionalLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
    ConvolutionalLayerFactory setWeightTensors(std::vector<std::vector<std::vector<float>>> weightTensors);
    PoolingLayConvolutionalLayerFactoryerFactory setStride(int stride);
    ConvolutionalLayerFactory setPadding(int padding);

private:
    std::vector<std::vector<std::vector<float>>> weightTensors;
    int stride;
    int padding;
};
#endif