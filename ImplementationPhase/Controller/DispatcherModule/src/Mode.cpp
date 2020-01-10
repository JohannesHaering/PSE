#include "Mode.h"

Mode::Mode();

string Mode::getModeName() { return modeName; }

void Mode::setAllowedDeviceList(std::list<Device> deviceList) { this->deviceList = deviceList; }

void Mode::setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

void Mode::setImageList(list<Image> imageList) {this->imageList = imageList; }

std::list<Device, std::list<NeuralNetwork>, std::list<image>> Mode::getImageDistribution()
	
virtual std::pair<float, float> calculate(std::list<Device> deviceList, int imgAmount) = 0; //abstract class
