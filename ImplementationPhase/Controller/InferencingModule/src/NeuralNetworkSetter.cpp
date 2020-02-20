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
#include <iostream>

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
	std::list<std::string> labels = std::list<std::string>{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	NeuralNetwork network = NeuralNetwork("Das beschte netz", 28, 28, 1);
	network.setLabels(labels);
  std::vector<NeuralNetworkAdapter> neuralNetworks; 
  LeakyReLuLayer* llayer = new LeakyReLuLayer();
	
  //ConvolutionLayer* clayer2 = new ConvolutionLayer(3, 3, 1, 32, 1, 0);
  //network.addLayer(clayer2);

  //network.addLayer(llayer);

  //FlattenLayer* flayer = new FlattenLayer();
  //network.addLayer(flayer);

  DenseLayer* dlayer = new DenseLayer(28 * 28, 320);
	network.addLayer(dlayer);
 
  //network.addLayer(llayer);

  //DenseLayer* dlayer2 = new DenseLayer(2, 10);
	//network.addLayer(dlayer2);

  SoftmaxLayer* smlayer = new SoftmaxLayer();
  network.addLayer(smlayer);

	//NeuralNetworkFacade neuralNetworkFacade;
  //neuralNetworkFacade.saveNeuralNetwork(network, "/home/pselabw1920/Downloads/testnetwork.txt");
  //NeuralNetwork neuralNetwork = neuralNetworkFacade.loadNeuralNetwork("/home/pselabw1920/Downloads/testnetwork.txt");
  //neuralNetworkFacade.saveNeuralNetwork(neuralNetwork, "/home/pselabw1920/Downloads/testbacknetwork.txt");
    /*for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
        neuralNetworks.push_back(neuralNetworkFacade.loadNeuralNetwork(*it));
    }  /*
	std::list<std::string> labels = std::list<std::string>{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	NeuralNetwork network = NeuralNetwork("Das beschte netz", 28, 28, 1);
	network.setLabels(labels);

//  ConvolutionLayer* clayer1 = new ConvolutionLayer(3, 3, 1, 32, 1, 0);
 // network.addLayer(clayer1);

  LeakyReLuLayer* llayer = new LeakyReLuLayer();
 // network.addLayer(llayer);

  //ConvolutionLayer* clayer2 = new ConvolutionLayer(3, 3, 1, 32, 1, 0);
  //network.addLayer(clayer2);

  //network.addLayer(llayer);

  //FlattenLayer* flayer = new FlattenLayer();
  //network.addLayer(flayer);

  DenseLayer* dlayer = new DenseLayer(28 * 28, 320);
	network.addLayer(dlayer);
 
  network.addLayer(llayer);

  DenseLayer* dlayer2 = new DenseLayer(320, 10);
	network.addLayer(dlayer2);

  SoftmaxLayer* smlayer = new SoftmaxLayer();
  network.addLayer(smlayer);
  
/*
  NeuralNetwork network2 = NeuralNetwork("Das 2. beschte netz", 28, 28, 1);
  network2.setLabels(labels);
    
   DenseLayer* dlayer3 = new DenseLayer(28 * 28, 300);
   network2.addLayer(dlayer3);
  
   LeakyReLuLayer* llayer2 = new LeakyReLuLayer();
   network2.addLayer(llayer2);
   
   DenseLayer* dlayer4 = new DenseLayer(300, 10);
   network2.addLayer(dlayer4);
  
   SoftmaxLayer* smlayer2 = new SoftmaxLayer();
   network2.addLayer(smlayer2);

*/
  neuralNetworks.push_back(network);
 // neuralNetworks.push_back(network2);
  inferencer->addNeuralNetwork(neuralNetworks);
  inferencer->enableStart();
}

/*
* Returns the inferencer assigned to this object.
*/
Inferencer* NeuralNetworkSetter::getInferencer() {
	return inferencer;
}

