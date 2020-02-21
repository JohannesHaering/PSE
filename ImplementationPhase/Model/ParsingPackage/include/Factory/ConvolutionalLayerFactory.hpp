#ifndef CONVOLUTIONAL_LAYER_FACTORY_H_
#define CONVOLUTIONAL_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

#include <vector>

class ConvolutionalLayerFactory : public LayerFactory
{
public:
    NetworkLayer* buildLayer() override;
    ConvolutionalLayerFactory* setWeightTensors(TENSOR(float) weightTensors);
    ConvolutionalLayerFactory* setStride(int stride);
    ConvolutionalLayerFactory* setPadding(int padding);

private:
    TENSOR(float) weightTensors;
    int stride;
    int padding;
};
#endif