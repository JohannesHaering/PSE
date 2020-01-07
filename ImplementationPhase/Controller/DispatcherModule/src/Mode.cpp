#include "Mode.h"

Mode::Mode();

string Mode::getModeName() { return modeName; }

void Mode::setAllowedDeviceList(list<Device> deviceList) { this->deviceList = deviceList; }

void Mode::setNeuralNetworkList(list<NeuralNetwork> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }

void Mode::setImageList(list<Image> imageList) {this->imageList = imageList; }

list<Device, list<NeuralNetwork>, list<image>> Mode::getImageDistribution()
	
virtual std::pair<float, float> calculate(list<Device> deviceList, int imgAmount) = 0; //abstract class
