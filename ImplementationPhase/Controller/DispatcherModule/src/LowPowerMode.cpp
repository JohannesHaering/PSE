#include <list>
#include <tuple>
#include <map>
#include "LowPowerMode.hpp"
#include "Device.hpp"
#include "PowerPredictorFromFile.hpp"

LowPowerMode::LowPowerMode() : Mode("LowPowerMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> LowPowerMode::getImageDistribution(std::list<cv::Mat> imageList)
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  std::list<std::string> deviceStringList;
  for (auto it : deviceList)
  {
    deviceStringList.push_back(it.getName());
  }

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

  std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> result;
  std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>* resultEntry;
  std::get<0>(*resultEntry) = *lowestPowerDevice;
  std::get<1>(*resultEntry) = this->neuralNetworkList;
  std::get<2>(*resultEntry) = imageList;
  result.push_back(*resultEntry);

  return result;
}
