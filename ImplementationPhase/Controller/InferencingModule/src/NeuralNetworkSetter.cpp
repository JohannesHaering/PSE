#include "Inferencer.hpp"
#include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetworkSetter.hpp"
#include "LeakyReLuLayer.hpp"
#include "SoftmaxLayer.hpp"
#include "FlattenLayer.hpp"
#include "ConvolutionLayer.hpp"
#include "MaxPoolLayer.hpp"
#include <vector>
#include <stdexcept>

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
  NeuralNetworkFacade neuralNetworkFacade = NeuralNetworkFacade();  
	std::list<std::string> labels = std::list<std::string>{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	NeuralNetwork network = NeuralNetwork("ConvConv", 28, 28, 1);
	network.setLabels(labels);
  for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
     neuralNetworks.push_back(neuralNetworkFacade.loadNeuralNetwork(*it));
  }
  if (neuralNetworks.size()== 0) {
    throw std::invalid_argument( "No neural networks chosen!" );
  }
  inferencer->addNeuralNetwork(neuralNetworks);
  inferencer->enableStart();
}

/*
* Returns the inferencer assigned to this object.
*/
Inferencer* NeuralNetworkSetter::getInferencer() {
	return inferencer;
}

