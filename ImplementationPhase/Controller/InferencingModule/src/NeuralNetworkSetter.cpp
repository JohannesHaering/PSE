#include "Inferencer.hpp"
// #include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetworkSetter.hpp"
#include "LeakyReLuLayer.hpp"
#include "SoftmaxLayer.hpp"
#include <vector>

/*
* Creates a NeuralNetworkSetter.
* Parameters:
* -Inferencer inferencer: the inferencer to set the neural networks
*/
NeuralNetworkSetter::NeuralNetworkSetter(Inferencer *inferencer) : inferencer(inferencer) { }

/*
* Takes the directories of the neural networks and sets the complete neural networks objects to the inferencer.
* Parameters: 
* -std::vector<std::string> directories: the directories of the neural networks
*/
void NeuralNetworkSetter::setNeuralNetwork(std::vector<std::string> directories) {
    std::vector<NeuralNetworkAdapter> neuralNetworks; 
	/*
	NeuralNetworkFacade neuralNetworkFacade;
    for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
        neuralNetworks.push_back(neuralNetworkFacade.loadNeuralNetwork(*it));
    }  */
	NeuralNetwork network = NeuralNetwork("Das beschte netz", 28, 28, 1);
	
    DenseLayer* dlayer = new DenseLayer(28 * 28, 300);
	network.addLayer(dlayer);

	LeakyReLuLayer* llayer = new LeakyReLuLayer();
    network.addLayer(llayer);

	DenseLayer* dlayer2 = new DenseLayer(300, 10);
	network.addLayer(dlayer2);

    SoftmaxLayer* smlayer = new SoftmaxLayer();
    network.addLayer(smlayer);
	
    neuralNetworks.push_back(network);

    inferencer->addNeuralNetwork(neuralNetworks);
    inferencer->enableStart();
}

/*
* Returns the inferencer assigned to this object.
*/
Inferencer* NeuralNetworkSetter::getInferencer() {
	return inferencer;
}

