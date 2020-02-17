#include "LayerFactory.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "ConvolutionLayer.hpp"
#include "NetworkLayer.hpp"
#include "MatrixDefine.hpp"

#include <vector>

NetworkLayer* ConvolutionalLayerFactory::buildLayer()
{
    /*ConvolutionLayer* layer = new ConvolutionLayer();
    layer->setInputDimension(inputDimensions);
    layer->setBatchSize(batchSize);
    layer->setWidth(width);
    layer->setHeight(height);
    layer->setZ(z);

    layer->setWeightsTensor(weightTensors);
    layer->setStride(stride);
    layer->setPadding(padding);
    
    return layer;*/
    return new ConvolutionLayer(3,3,z, 32,1,0);//please fix your factory Johannes
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
