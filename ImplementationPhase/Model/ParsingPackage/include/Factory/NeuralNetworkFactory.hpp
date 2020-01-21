#ifndef NEURALNETWORK_FACTORY_H_
#define NEURALNETWORK_FACTORY_H_

#include "NeuralNetwork.hpp"
#include "NetworkLayer.hpp"

#include <string>
#include <list>

class NeuralNetworkFactory
{
public:
    NeuralNetwork buildNeuralNetwork();
    NeuralNetworkFactory setName(std::string name);
    NeuralNetworkFactory setLayers(std::list<NetworkLayer> layers);
    NeuralNetworkFactory setHeight(int height);
    NeuralNetworkFactory setWidth(int width);
    NeuralNetworkFactory setChannels(int channels);

private:
    int height;
    int width;
    int channels;
    std::string name;
    std::list<NetworkLayer> layers;
};
#endif