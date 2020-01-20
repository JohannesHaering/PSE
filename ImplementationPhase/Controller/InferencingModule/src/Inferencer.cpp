#include "NeuralNetworkAdapter.hpp"
#include "Inferencer.hpp"
#include <vector>
 
 /*
  * Saves the given neural networks
  * Parameters:
  * -std::vector<NeuralNetworkAdapter> neuralNetwork: The neural networks to be saved
  */
void Inferencer::addNeuralNetwork(std::vector<NeuralNetworkAdapter> neuralNetwork) {
	this->neuralNetworks = neuralNetwork;
}

/*
* Returns the amount of saved neural networks.
*/
int Inferencer::getAmountNeuralNetworks() { return neuralNetworks.size(); }

