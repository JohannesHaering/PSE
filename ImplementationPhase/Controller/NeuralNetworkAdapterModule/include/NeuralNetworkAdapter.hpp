#ifndef _NEURAL_NETWORK_ADAPTER_H_
#define _NEURAL_NETWORK_ADAPTER_H_
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
        NeuralNetworkAdapter(NeuralNetwork neuralNetwork);

        void addLayer(NetworkLayer layer);
		NetworkLayer* getFirstLayer();
		NetworkLayer* getLastLayer();
		NetworkLayer* getNextLayer();
		NetworkLayer* getPreviousLayer();

    private: 
        NeuralNetwork neuralNetwork;    
        
};
#endif
