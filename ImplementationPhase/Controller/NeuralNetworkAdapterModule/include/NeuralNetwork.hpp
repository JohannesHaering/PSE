#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

#include <string>
#include "NeuralNetworkLayer.hpp"

class NeuralNetwork {
    public:
        NeuralNetwork();
        NeuralNetwork(std::string name);

        void addLayer(NeuralNetworkLayer layer);
        NeuralNetworkLayer getFirstLayer();
        NeuralNetworkLayer getLastLayer();
        NeuralNetworkLayer getNextLayer();
        NeuralNetworkLayer getPreviousLayer();
};
#endif