#include <list>
#include <tuple>
#include <map>
#include "LowPowerMode.hpp"
#include "Device.hpp"
#include "PowerPredictorFromfile.hpp"

LowPowerMode::LowPowerMode() : Mode("LowPowerMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
list<Device, std::list<NeuralNetwork>, std::list<cv::Mat>> Mode::getImageDistribution(std::list<cv::mat> imageList) 
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  std::list<std::string> deviceStringList;
  for (auto const& it : DeviceList) 
  {
    deviceStringList.push_back(it->name);
  }

  int lowestPower = 9999; //There will be a device drawing less then 9999 Watt...
  Device lowestPowerDevice;
  PowerPredictorFromFile predictor = PowerPredictorFromFile();
  std::map<std::string, float> powerPredictions = predictor.predict(deviceStringList);
  std::list<Device>::iterator deviceIterator = deviceList.begin();

  for (auto const& it : powerPredictions) 
  {
    if (it->second() < lowestPower)
    {
      lowestPower = it->second();
      lowestPowerDevice = deviceIterator;
    }
    ++deviceIterator;
  }	  

  std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>> result;
  std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>> resultEntry;
  get<0>(resultEntry) = lowestPowerDevice;
  get<1>(resultEntry) = this->neuralNetworkList;
  get<2>(resultEntry) = imageList;
  result.push_back(resultEntry);

}

