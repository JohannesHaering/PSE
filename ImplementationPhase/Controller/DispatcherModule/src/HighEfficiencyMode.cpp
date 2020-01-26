#include <list>
#include <tuple>
#include <map>
#include "HighEfficiencyMode.hpp"
#include "Device.hpp"
#include "PowerPredictorFromFile.hpp"
#include "PerformancePredictorFromFile.hpp"

HighEfficiencyMode::HighEfficiencyMode() : Mode("HighEfficiencyMode") {}

//Basic implementation, assignes all images to the most efficient device.
//Can be improved, e.g. by taking into consideration the host power usage and therefore using less efficient devices too.
std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> HighEfficiencyMode::getImageDistribution(std::list<cv::Mat> imageList)
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  std::list<std::string> deviceStringList;
  for (auto it : deviceList)
  {
    deviceStringList.push_back(it.getName());
  }

  double bestEfficiency = 0; //There will be a more efficient device.
  Device* mostEfficientDevice;
  Device* lowestPowerDevice;
  PowerPredictorFromFile*       powerPredictor       = new PowerPredictorFromFile();
  PerformancePredictorFromFile* performancePredictor = new PerformancePredictorFromFile();
  std::map<std::string, float> powerPredictions       = powerPredictor->predict(deviceStringList);
  std::map<std::string, float> performancePredictions = performancePredictor->predict(deviceStringList);
  std::map<std::string, float>::iterator powerIterator = powerPredictions.begin();
  std::map<std::string, float>::iterator performanceIterator = performancePredictions.begin();
  std::list<Device>::iterator deviceIterator = deviceList.begin();

  while (powerIterator != powerPredictions.end()) 
  {
    float deviceEfficiency = performanceIterator->second / powerIterator->second;
    if (deviceEfficiency > bestEfficiency)
    {
      mostEfficientDevice = &*deviceIterator;
      lowestPowerDevice = &*deviceIterator;
    }
    ++powerIterator;
    ++performanceIterator;
    ++deviceIterator;
  }	  

  std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> result;
  std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>* resultEntry;
  std::get<0>(*resultEntry) = *mostEfficientDevice;
  std::get<1>(*resultEntry) = this->neuralNetworkList;
  std::get<2>(*resultEntry) = imageList;
  result.push_back(*resultEntry);

  return result;
}

