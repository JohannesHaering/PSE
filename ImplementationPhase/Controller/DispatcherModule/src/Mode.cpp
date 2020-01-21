#include <string>
#include <algorithm>

#include <opencv2/opencv.hpp>

#include "Device.hpp"
#include "NeuralNetworkAdapter.hpp"

#include "Mode.hpp"

Mode::Mode(std::string modeName) : modeName(modeName) {}

std::string Mode::getModeName() { return modeName; }

void Mode::setAllowedDeviceList(std::list<Device> deviceList) { this->deviceList = deviceList; }
std::list<Device> Mode::getAllowedDeviceList() { return deviceList; }

void Mode::setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }
std::list<NeuralNetworkAdapter> Mode::getNeuralNetworkList() { return neuralNetworkList; }

//std::list<Device, std::list<NeuralNetworkAdapter>, std::list<image>> Mode::getImageDistribution(std::list<cv::Mat>) = 0;
