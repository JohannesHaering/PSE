#ifndef NEURAL_NETWORK_ADAPTER_H_
#define NEURAL_NETWORK_ADAPTER_H_

#include <string>
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
		NeuralNetworkAdapter();
        NeuralNetworkAdapter(NeuralNetwork neuralNetwork);

        void addLayer(NeuralNetworkLayer layer);
		NeuralNetworkLayer getFirstLayer();
		NeuralNetworkLayer getLastLayer();
		NeuralNetworkLayer getNextLayer();
		NeuralNetworkLayer getPreviousLayer();

    private: 
        NeuralNetwork neuralNetwork;    
        
};
#endif