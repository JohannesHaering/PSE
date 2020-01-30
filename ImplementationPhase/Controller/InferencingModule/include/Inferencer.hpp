#ifndef INFERENCER_H_
#define INFERENCER_H_

#include "NeuralNetworkAdapter.hpp"
#include "ContentView.hpp"
#include <vector>

// class NeuralNetworkAdapter;

class Inferencer {

    protected:
		std::vector<NeuralNetworkAdapter> neuralNetworks;

    public:
		void addNeuralNetwork(std::vector<NeuralNetworkAdapter> neuralNetwork);
		int getAmountNeuralNetworks();
        virtual void startProcess() = 0;
        virtual bool canStart() = 0;;
        virtual void enableStart() = 0;;
		ContentView* getPage();

    private:
        ContentView* page;

};
#endif
