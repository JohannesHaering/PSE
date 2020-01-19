#ifndef COLLECT_RESULT_LAYER_FACTORY_H_
#define COLLECT_RESULT_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"

class CollectResultsLayerFactory : public LayerFactory {
    NetworkLayer buildLayer() override;
};
#endif