#include "NeuralNetwork.hpp"
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetworkFactory.hpp"

#include <string>
#include <list>

NeuralNetwork NeuralNetworkFactory::buildNeuralNetwork()
{
    NeuralNetwork neuralNetwork(name);
    for (auto it = layers.begin(); it != layers.end(); ++it)
    {
        neuralNetwork.addLayer(*it);
    }

    return neuralNetwork;
}

NeuralNetworkFactory NeuralNetworkFactory::setName(std::string name)
{
    this->name = name;
    return *this;
}

NeuralNetworkFactory NeuralNetworkFactory::setLayers(std::list<NeuralNetworkLayer> layers)
{
    this->layers = layers;
    return *this;
}

NeuralNetworkFactory NeuralNetworkFactory::setHeight(int height)
{
    this->height = height;
    return *this;
}

NeuralNetworkFactory NeuralNetworkFactory::setWidth(int width)
{
    this->width = width;
    return *this;
}

NeuralNetworkFactory NeuralNetworkFactory::setChannels(int channels)
{
    this->channels = channels;
    return *this;
}