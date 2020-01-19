#include "Inferencer.hpp"
#include "NeuralNetworkSetter.hpp"
#include "FileExplorerHandler.hpp"
#include "NeuralNetworkHandler.hpp"
#include "viewfacade.h"
#include <stdexcept>

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
	try {
		neuralnetworksetter.setNeuralNetwork(directories);
	}
	catch (const std::invalid_argument& ia)
	{
		neuralnetworksetter.getInferencer().getPage().showError("Invalid neural network");
	}
}

/*
 * Calls the view to open a file explorer and gets the chosen directories.
 */
std::vector<std::string> NeuralNetworkHandler::fetchDirectory() {
	return neuralnetworksetter.getInferencer().getPage().getFilesFromExplorer(validformats);
}


