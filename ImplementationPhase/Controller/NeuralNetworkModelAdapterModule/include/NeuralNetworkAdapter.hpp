#ifndef NEURAL_NETWORK_ADAPTER_H_
#define NEURAL_NETWORK_ADAPTER_H_

#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
		NeuralNetworkAdapter();
        NeuralNetworkAdapter(NeuralNetwork neuralNetwork);

        void addLayer(NetworkLayer *layer);
		NetworkLayer *getFirstLayer();
		NetworkLayer *getLastLayer();
		NetworkLayer *getNextLayer();
		NetworkLayer *getPreviousLayer();
		std::string getName();

    private: 
        NeuralNetwork neuralNetwork;    
        
};
#endif
