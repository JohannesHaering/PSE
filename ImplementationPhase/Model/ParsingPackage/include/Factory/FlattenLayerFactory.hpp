#ifndef FLATTEN_LAYER_FACTORY_H_
#define FLATTEN_LAYER_FACTORY_H_

#include "NeuralNetworkLayer.hpp"
#include "LayerFactory.hpp"

class FlattenLayerFactory : public LayerFactory
{
public:
    NeuralNetworkLayer buildLayer() override;
};
#endif