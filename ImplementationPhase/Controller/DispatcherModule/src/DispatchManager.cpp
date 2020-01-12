#include "DispatchManager.h"

//DispatchManager::DispatchManager() {}
//DispatchManager::DispatchManager(DispatchManager const& copy); //not implemented
//DispatchManager::DispatchManager& operator=(DispatchManager const& copy); //not implemented

DispatchManager& DispatchManager::getInstance() 
{
	static DispatchManager instance;
	return instance;
}

Mode DispatchManager::getMode() { return mode; }

void DispatchManager::setMode(Mode operatingMode) { this->mode = operatingMode; }

void DispatchManager::setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

std::list<NeuralNetwork> DispatchManager::getNeuralNetworkList() { return neuralNetworkList; }

std::list<Mode> DispatchManager::getModeList() 
{
	//TODO
	return NULL;
}

ResultManager DispatchManager::dispatchImages(std::list<image> imageList) 
{
	//TODO
}
