#ifndef LOCAL_RESPONSE_NORMALIZATION_LAYER_FACTORY_H_
#define LOCAL_RESPONSE_NORMALIZATION_LAYER_FACTORY_H_

#include "LayerFactory.hpp"
#include "NetworkLayer.hpp"
#include "LRNType.hpp"

class LocalResponseNormalizationLayerFactory : public LayerFactory
{
public:
    NetworkLayer buildLayer() override;
    LocalResponseNormalizationLayerFactory setType(LRNType type);
    LocalResponseNormalizationLayerFactory setDepth(int depth);

private:
    LRNType type;
    int depth;
};
#endif