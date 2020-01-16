#ifndef INFERENCER_H_
#define INFERENCER_H_
#include <vector>
#include "NeuralNetworkAdapter.hpp"
#include <vector>

class Inferencer {

	protected:
		std::vector<NeuralNetworkAdapter> neuralNetworks;

    public: 
		void addNeuralNetwork(std::vector<NeuralNetworkAdapter> neuralNetwork);
		int getAmountNeuralNetworks();
        virtual void startProcess(); 
        virtual bool canStart();
        virtual void enableStart(); 

};
#endif
