#ifndef FLATTEN_LAYER_FACTORY_H_
#define FLATTEN_LAYER_FACTORY_H_

#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"

class FlattenLayerFactory : public LayerFactory
{
public:
    NetworkLayer* buildLayer() override;
};
#endif