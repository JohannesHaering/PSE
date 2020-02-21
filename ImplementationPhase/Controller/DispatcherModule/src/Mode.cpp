#include <string>
#include <algorithm>

#include <opencv2/opencv.hpp>

#include "Device.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "ImageFacade.hpp"

#include "Mode.hpp"

Mode::Mode(std::string modeName) : modeName(modeName) {}

std::string Mode::getModeName() { return modeName; }

void Mode::setAllowedDeviceList(std::list<Device> deviceList) { this->deviceList = deviceList; }
std::list<Device> Mode::getAllowedDeviceList() { return deviceList; }

void Mode::setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList) { this->neuralNetworkList = neuralNetworkList; }
std::list<NeuralNetworkAdapter> Mode::getNeuralNetworkList() { return neuralNetworkList; }

//std::list<Device, std::list<NeuralNetworkAdapter>, std::list<image>> Mode::getImageDistribution(std::list<cv::Mat>) = 0;
std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> Mode::getTrivialDistribution(std::list<std::string> imageList){
  
  std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> result;
  for (auto nnit : neuralNetworkList) {
    std::vector<std::string> dirVector = std::vector<std::string>(imageList.begin(), imageList.end());
    std::list<cv::Mat> matList = ImageFacade().getImages(imageList, nnit.getWidth(), nnit.getHeight(),nnit.getChannels());
    std::vector<cv::Mat> matVec = std::vector<cv::Mat>(matList.begin(), matList.end());
    TENSOR(float) tens = ImageFacade().createImageTensor(matVec, nnit.getWidth(), nnit.getHeight());
    
  
    DeviceType type = DeviceType::CPP;

    auto res = std::make_tuple(type, nnit, tens, dirVector);
    result.push_back(res);
  }
  return result;

}
