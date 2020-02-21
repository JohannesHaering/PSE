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
  std::vector<NeuralNetworkAdapter> neuralNetworks; 
  NeuralNetworkFacade neuralNetworkFacade = NeuralNetworkFacade();  
	std::list<std::string> labels = std::list<std::string>{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	NeuralNetwork network = NeuralNetwork("ConvConv", 28, 28, 1);
	network.setLabels(labels);
  /*
  LeakyReLuLayer* llayer = new LeakyReLuLayer();
	
  ConvolutionLayer* clayer2 = new ConvolutionLayer(3, 3, 1, 32, 1, 0);
  network.addLayer(clayer2);

  network.addLayer(llayer);
  
  ConvolutionLayer* clayer = new ConvolutionLayer(3,3,32,32,1,0);
  network.addLayer(clayer);

  SoftmaxLayer* slayer = new SoftmaxLayer();
  network.addLayer(slayer);
  
  neuralNetworkFacade.saveNeuralNetwork(network, "/home/pselabw1920/Documents/randomnetworks/convconvnetwork.txt");
  
	NeuralNetwork network2 = NeuralNetwork("ConvConvDense", 28, 28, 1);
	network2.setLabels(labels);

  LeakyReLuLayer* llayer = new LeakyReLuLayer();
  ConvolutionLayer* clayer = new ConvolutionLayer(3,3,1,32,1,0);
  ConvolutionLayer* clayer2 = new ConvolutionLayer(3, 3, 32, 32, 1, 0);
  DenseLayer* dlayer = new DenseLayer(24 * 24 * 32, 10);
  SoftmaxLayer* slayer = new SoftmaxLayer();
  network2.addLayer(clayer);
  network2.addLayer(llayer);
  network2.addLayer(clayer2);
  network2.addLayer(llayer);
	dlayer->setMode(DeviceType::CPU);
  network2.addLayer(dlayer);
  network2.addLayer(slayer);

  neuralNetworkFacade.saveNeuralNetwork(network2, "/home/pselabw1920/Documents/randomnetworks/convconvdensenetwork.txt");
  
  //neuralNetworks.push_back(network);
  neuralNetworks.push_back(network2);
*/
  for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
     neuralNetworks.push_back(neuralNetworkFacade.loadNeuralNetwork(*it));
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

