#include "LayerFactory.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "ConvolutionLayer.hpp"
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

#include <vector>

NetworkLayer* ConvolutionalLayerFactory::buildLayer()
{
    ConvolutionLayer* layer = new ConvolutionLayer(weightTensors, stride, padding);
    layer->setBatchSize(batchSize);
    layer->setWidth(width);
    layer->setHeight(height);
    layer->setZ(z);
    
    return layer;
}

ConvolutionalLayerFactory* ConvolutionalLayerFactory::setWeightTensors(TENSOR(float) weightTensors)
{
    this -> weightTensors = weightTensors;
    return this;
}

ConvolutionalLayerFactory* ConvolutionalLayerFactory::setStride(int stride)
{
    this -> stride = stride;
    return this;
}
ConvolutionalLayerFactory* ConvolutionalLayerFactory::setPadding(int padding)
{
    this -> padding = padding;
    return this;
}
