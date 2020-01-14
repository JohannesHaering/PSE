#ifndef COLLECT_RESULT_LAYER_FACTORY_H_
#define COLLECT_RESULT_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NeuralNetworkLayer.hpp"

class CollectResultLayerFactory : public LayerFactory {
    NeuralNetworkLayer CollectResultLayerFactory::buildLayer() override;
};
#endif