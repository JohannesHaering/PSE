#ifndef INFERENCER_H_
#define INFERENCER_H_

#include "NeuralNetworkAdapter.hpp"
#include "ContentView.hpp"
#include <vector>

// class NeuralNetworkAdapter;

class Inferencer {

    protected:
		std::vector<NeuralNetworkAdapter> neuralNetworks;
		ContentView* page;

    public:
		void addNeuralNetwork(std::vector<NeuralNetworkAdapter> neuralNetwork);
		int getAmountNeuralNetworks();
		virtual void startProcess();
		virtual bool canStart();
		virtual void enableStart();
		ContentView* getPage();

};
#endif
