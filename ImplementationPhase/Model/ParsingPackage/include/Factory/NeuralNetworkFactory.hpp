#ifndef NEURALNETWORK_FACTORY_H_
#define NEURALNETWORK_FACTORY_H_

#include "NeuralNetwork.hpp"
#include "NeuralNetworkLayer.hpp"

#include <string>
#include <list>

class NeuralNetworkFactory
{
public:
    NeuralNetwork buildNeuralNetwork();
    NeuralNetworkFactory setName(std::string name);
    NeuralNetworkFactory setLayers(std::list<NeuralNetworkLayer> layers);

private:
    std::string name;
    std::list<NeuralNetworkLayer> layers;
};
#endif