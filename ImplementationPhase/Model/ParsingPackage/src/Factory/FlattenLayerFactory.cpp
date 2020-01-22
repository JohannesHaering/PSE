#include "FlattenLayerFactory.hpp"
#include "FlattenLayer.hpp"
#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"

NetworkLayer FlattenLayerFactory::buildLayer(){
    return FlattenLayer(name, inputDimensions);
}