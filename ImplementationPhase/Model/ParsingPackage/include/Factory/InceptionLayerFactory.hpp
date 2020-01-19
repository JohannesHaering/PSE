#ifndef INCEPTION_LAYER_FACTORY_H_
#define INCEPTION_LAYER_FACTORY_H_

#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetwork.hpp"

class InceptionLayerFactory : public LayerFactory
{
public:
    NetworkLayer buildLayer() override;
    InceptionLayerFactory addLayerChain(NeuralNetwork chain);

private:
    NeuralNetwork chain;
};
#endif