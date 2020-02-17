#include "ActivationLayerFactory.hpp"
#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "ActivationLayer.hpp"
#include "Activation.hpp"
#include "SoftmaxLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "ReLuLayer.hpp"
#include "SigmoidLayer.hpp"

NetworkLayer* ActivationLayerFactory::buildLayer()
{
    NetworkLayer* layer;
    switch (activation) {
    case Activation::LEAKING_RELU:
        layer = new LeakyReLuLayer();
    case Activation::RELU:
        layer = new ReLuLayer();
    case Activation::SOFTMAX:
        layer = new SoftmaxLayer();
    case Activation::SIGMOID:
        layer = new SigmoidLayer();
    default:
        layer = new SoftmaxLayer();
    }
    //layer->setBatchSize(batchSize);
    return layer;
}

ActivationLayerFactory ActivationLayerFactory::setActivation(Activation activation)
{
    this -> activation = activation;
    return *this;
}

ActivationLayerFactory ActivationLayerFactory::setAlpha(float alpha)
{
    this -> alpha = alpha;
    return *this;
}
