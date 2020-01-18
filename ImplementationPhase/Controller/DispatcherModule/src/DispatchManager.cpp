#include "DispatchManager.hpp"
#include "Channel.hpp"
#include "Mode.hpp"
#include "NeuralNetworkAdapter.hpp"
//#include "Device.hpp"

#include <opencv2/opencv.hpp>

//DispatchManager::DispatchManager() {}
//DispatchManager::DispatchManager(DispatchManager const& copy); //not implemented
//DispatchManager::DispatchManager& operator=(DispatchManager const& copy); //not implemented

DispatchManager& DispatchManager::getInstance() 
{
	static DispatchManager instance;
	return instance;
}

Mode& DispatchManager::getMode() { return mode; }

void DispatchManager::setMode(Mode& operatingMode) { this->mode = operatingMode; }

void DispatchManager::setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

std::list<NeuralNetworkAdapter> DispatchManager::getNeuralNetworkList() { return neuralNetworkList; }

std::list<Mode> DispatchManager::getModeList() 
{
	//TODO
	return NULL;
}

ResultManager DispatchManager::dispatchImages(std::list<cv::Mat> imageList) 
{
	//TODO
}
