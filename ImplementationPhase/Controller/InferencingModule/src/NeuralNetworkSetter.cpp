#include "Inferencer.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetworkSetter.hpp"
#include <vector>

/*
* Creates a NeuralNetworkSetter.
* Parameters:
* -Inferencer inferencer: the inferencer to set the neural networks
*/
NeuralNetworkSetter::NeuralNetworkSetter(Inferencer inferencer) : inferencer(inferencer) { }

/*
* Takes the directories of the neural networks and sets the complete neural networks objects to the inferencer.
* Parameters: 
* -std::vector<std::string> directories: the directories of the neural networks
*/
void NeuralNetworkSetter::setNeuralNetwork(std::vector<std::string> directories) {
    std::vector<NeuralNetworkAdapter> neuralNetworks; 
	NeuralNetworkFacade neuralNetworkFacade;
    for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
        neuralNetworks.push_back(neuralNetworkFacade.loadNeuralNetwork(*it));
    }  
    inferencer.addNeuralNetwork(neuralNetworks);
}

QString vectorToString(std::vector<std::string> formats) {
	std::string filter = "";
	for (std::vector<std::string>::iterator it = formats.begin(); it != formats.end(); ++it) {
		filter += *it + "-files (*." + *it + ") ;; ";
	}
	filter.truncate(filter.lastIndexOf(QChar(';'));
	filter.truncate(filter.lastIndexOf(QChar(';'));
	return filter;
}