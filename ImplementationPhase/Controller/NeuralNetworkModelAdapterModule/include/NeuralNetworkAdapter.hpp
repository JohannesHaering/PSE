#ifndef NEURALNETWORKADAPTER_H_
#define NEURALNETWORKADAPTER_H_
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
        NeuralNetworkAdapter();
        NeuralNetworkAdapter(std::string name);

        void addLayer(NetworkLayer layer);
        NetworkLayer getFirstLayer();
        NetworkLayer getLastLayer();
        NetworkLayer getNextLayer();
        NetworkLayer getPreviousLayer();

    private: 
        NeuralNetwork neuralNetwork;    
        
};
#endif
