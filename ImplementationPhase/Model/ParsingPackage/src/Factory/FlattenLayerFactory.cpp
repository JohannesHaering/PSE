#include "FlattenLayerFactory.hpp"
#include "FlattenLayer.hpp"
#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"

NetworkLayer* FlattenLayerFactory::buildLayer(){
    NetworkLayer* flattenLayer = new FlattenLayer();
    return flattenLayer;
}
