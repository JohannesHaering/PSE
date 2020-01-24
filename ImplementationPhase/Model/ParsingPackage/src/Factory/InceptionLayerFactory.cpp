#include "NetworkLayer.hpp"
#include "LayerFactory.hpp"
#include "NeuralNetwork.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"

NetworkLayer InceptionLayerFactory::buildLayer()
{
    auto layer =  InceptionLayer(name, inputDimensions);
	layer.addLayerChain(chain);
	return layer;
}
InceptionLayerFactory InceptionLayerFactory::addLayerChain(NeuralNetwork chain)
{
   this -> chain = chain;
    return *this;
}