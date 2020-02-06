#include "NeuralNetwork.hpp"
#include "NetworkLayer.hpp"
#include "NeuralNetworkFactory.hpp"

#include <string>
#include <list>

NeuralNetwork NeuralNetworkFactory::buildNeuralNetwork()
{
    NeuralNetwork neuralNetwork(name, width, height, channels);
    for (auto it = layers.begin(); it != layers.end(); ++it)
    {
        auto layer = *it;
        neuralNetwork.addLayer(&layer);
    }
    neuralNetwork.setLabels(labels);
    return neuralNetwork;
}

NeuralNetworkFactory NeuralNetworkFactory::setName(std::string name)
{
    this->name = name;
    return *this;
}

NeuralNetworkFactory NeuralNetworkFactory::setLayers(std::list<NetworkLayer> layers)
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

NeuralNetworkFactory NeuralNetworkFactory::setLabels(std::list<std::string> labels) {
    this->labels = labels;
    return *this;
}
