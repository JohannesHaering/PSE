#ifndef NETWORKLAYER_H_
#define NETWORKLAYER_H_
#include <string>
#include "NetworkLayer.hpp"

class NeuralNetwork {
    public:
        NeuralNetwork();
        NeuralNetwork(std::string name);

        void addLayer(NetworkLayer layer);
        NetworkLayer getFirstLayer();
        NetworkLayer getLastLayer();
        NetworkLayer getNextLayer();
        NetworkLayer getPreviousLayer();
};
#endif
