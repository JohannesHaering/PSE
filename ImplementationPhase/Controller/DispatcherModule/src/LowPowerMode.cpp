#include <list>
#include <tuple>
#include <map>
#include <iostream>
#include "LowPowerMode.hpp"
#include "Device.hpp"
#include "PowerPredictorFromFile.hpp"
#include "ImageFacade.hpp"

LowPowerMode::LowPowerMode() : Mode("LowPowerMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> LowPowerMode::getImageDistribution(std::list<std::string> imageList)
{

  if (imageList.size() == 0) {
    throw std::invalid_argument( "Cant split zero images" );
  }
  std::list<Device> deviceList = this->getAllowedDeviceList();
  if (deviceList.size() == 0)
    return getTrivialDistribution(imageList);
  std::list<std::string> deviceStringList;
  for (auto it : deviceList)
  {
    deviceStringList.push_back(it.getName());
  }

  std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> result;
  int lowestPower = 9999; //There will be a device drawing less then 9999 Watt...
  Device* lowestPowerDevice;
  PowerPredictorFromFile predictor = PowerPredictorFromFile();
  std::map<std::string, float> powerPredictions = predictor.predict(deviceStringList);
  std::list<Device>::iterator deviceIterator = deviceList.begin();

  for (auto it : powerPredictions)
  {
    if (it.second < lowestPower)
    {
      lowestPower = it.second;
      lowestPowerDevice = &*deviceIterator;
    }
    ++deviceIterator;
  }	  

  for (auto nnit : neuralNetworkList) {
  std::vector<std::string> dirVector = std::vector<std::string>(imageList.begin(), imageList.end());
  std::list<cv::Mat> matList = ImageFacade().getImages(imageList, nnit.getWidth(), nnit.getHeight(),nnit.getChannels());
  std::vector<cv::Mat> matVec = std::vector<cv::Mat>(matList.begin(), matList.end());
  TENSOR(float) tens = ImageFacade().createImageTensor(matVec, nnit.getWidth(), nnit.getHeight());
    
  std::string dev = lowestPowerDevice->getType();
  
  DeviceType type;
  if (dev.compare("CPU") == 0){
    type = DeviceType::CPU;
  } else {
     type = DeviceType::CPP; 
  }
  type = DeviceType::CPP;

  //std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>* resultEntry;
  //std::get<0>(*resultEntry) = type;
  //std::get<1>(*resultEntry) = nnit;
  //std::get<2>(*resultEntry) = tens;
  //std::get<3>(*resultEntry) = dirVector;

  auto res = std::make_tuple(type, nnit, tens, dirVector);
  result.push_back(res);
  }
  return result;
}
