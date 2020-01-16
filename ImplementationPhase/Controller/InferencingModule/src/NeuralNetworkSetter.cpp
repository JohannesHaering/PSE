#include "Inferencer.hpp"
#include "Model.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "NeuralNetworkSetter.hpp"
#include <vector>

/*
* Creates a NeuralNetworkSetter.
* Parameters:
* -Inferencer inferencer: the inferencer to set the neural networks
*/
NeuralNetworkSetter::NeuralNetworkSetter(Inferencer inferencer) : inferencer(inferencer), model(Model::getInstance()) { }

/*
* Takes the directories of the neural networks and sets the complete neural networks objects to the inferencer.
* Parameters: 
* -std::vector<std::string> directories: the directories of the neural networks
*/
void NeuralNetworkSetter::setNeuralNetwork(std::vector<std::string> directories) {
    std::vector<NeuralNetworkAdapter> nn; 
    for(std::vector<std::string>::iterator it = directories.begin(); it != directories.end(); ++it) {
        nn.push_back(model.parseNeuralNetwork(*it));
    }  
    inferencer.addNeuralNetwork(nn);
}

