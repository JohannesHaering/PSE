#include "ActivationLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "ActivationLayer.hpp"
#include "Activation.hpp"
#include "SoftmaxLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "ReLuLayer.hpp"
#include "SigmoidLayer.hpp"
#include "LayerType.hpp"

NetworkLayer* ActivationLayerFactory::buildLayer()
{
    NetworkLayer* layer;
    switch (activation) {
    case LayerType::LEAKYRELU:
        layer = new LeakyReLuLayer();
        break;
    case LayerType::RELU:
        layer = new ReLuLayer();
        break;
    case LayerType::SOFTMAX:
        layer = new SoftmaxLayer();
        break;
    case LayerType::SIGMOID:
        layer = new SigmoidLayer();
        break;
    default:
        layer = new SoftmaxLayer();
    }
    /*
    layer->setBatchSize(batchSize);
    layer->setWidth(width);
    layer->setHeight(height);
    layer->setZ(z);*/
    return layer;
}

ActivationLayerFactory ActivationLayerFactory::setActivation(LayerType activation)
{
    this -> activation = activation;
    return *this;
}

ActivationLayerFactory ActivationLayerFactory::setAlpha(float alpha)
{
    this -> alpha = alpha;
    return *this;
}
