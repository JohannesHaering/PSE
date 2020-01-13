#include "Inferencer.hpp"
#include "NeuralNetworkSetter.hpp"
#include "FileExplorerHandler.hpp"
#include "NeuralNetworkHandler.hpp"
#include "ViewFacade.hpp"

/**
 * Creates a NeuralNetworkHandler that creates a neural network setter.
 * Parameters:
 * -Inferencer inferencer: The inferencer to set the neural networks to.
 */
NeuralNetworkHandler::NeuralNetworkHandler(Inferencer inferencer)
{
    neuralnetworksetter = NeuralNetworkSetter(inferencer);
}

/**
 * Sends the directories to the neural network setter to set the neural networks of the inferencer.
 * Parameters:
 * -std::vector<std::string> directories: The directories of the neural networks.
 */
void NeuralNetworkHandler::sendDirectory(std::vector<std::string> directories)
{
    neuralnetworksetter.setNeuralNetwork(directories);
}

/*
 * Calls the view to open a file explorer and gets the chosen directories.
 */
std::vector<std::string> NeuralNetworkHandler::fetchDirectory() {
	view.getDirectories(validformats);
}


