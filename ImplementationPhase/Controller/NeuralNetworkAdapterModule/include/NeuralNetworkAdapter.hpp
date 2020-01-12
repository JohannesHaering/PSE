#include <string>
#include "NeuralNetworkLayer.hpp"
#include "NeuralNetwork.hpp"

class NeuralNetworkAdapter {

    public:
        NeuralNetworkAdapter(NeuralNetwork neuralNetwork);

        void addLayer(NeuralNetworkLayer layer);
		NeuralNetworkLayer getFirstLayer();
		NeuralNetworkLayer getLastLayer();
		NeuralNetworkLayer getNextLayer();
		NeuralNetworkLayer getPreviousLayer();

    private: 
        NeuralNetwork neuralNetwork;    
        
};