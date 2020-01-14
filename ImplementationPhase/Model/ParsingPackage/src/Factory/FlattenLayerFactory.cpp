#include "FlattenLayerFactory.hpp"
#include "FlattenLayer.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerFactory.hpp"

NeuralNetworkLayer FlattenLayerFactory::buildLayer(){
    return FlattenLayer(name, inputDimensions);
}