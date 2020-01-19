#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetwork.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"

NetworkLayer InceptionLayerFactory::buildLayer()
{
    return InceptionLayer(name, inputDimensions, chain);
}
InceptionLayerFactory InceptionLayerFactory::addLayerChain(NeuralNetwork chain)
{
   this -> chain = chain;
    return *this;
}