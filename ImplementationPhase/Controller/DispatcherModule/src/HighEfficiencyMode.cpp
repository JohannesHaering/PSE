#include <list>
#include <tuple>
#include <map>
#include "HighEfficiencyMode.hpp"
#include "Device.hpp"
#include "PowerPredictorFromfile.hpp"

HighEfficiencyMode::HighEfficiencyMode() : Mode("HighEfficiencyMode") {}

//Basic implementation, assignes all images to the most efficient device.
//Can be improved, e.g. by taking into consideration the host power usage and therefore using less efficient devices too.
std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> Mode::getImageDistribution(std::list<cv::mat> imageList) 
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  std::list<std::string> deviceStringList;
  for (auto const& it : DeviceList) 
  {
    deviceStringList.push_back(it->name);
  }

  double bestEfficiency = 0; //There will be a more efficient device.
  Device mostEfficientDevice;
  PowerPredictorFromFile       powerPredictor       = PowerPredictorFromFile();
  PerformancePredictorFromFile performancePredictor = PerformancePredictorFromFile();
  std::map<std::string, float> powerPredictions       = predictor.predict(deviceStringList);
  std::map<std::string, float> performancePredictions = predictor.predict(deviceStringList);
  std::map<std::string, float>::iterator powerIterator = powerPredictions.begin();
  std::list<Device>::iterator deviceIterator = deviceList.begin();

  while (powerIterator != powerPredictions.end()) 
  {
    deviceEfficiency = performanceIterator->second() / powerIterator->second();
    if (deviceEfficiency > bestEfficiency)
    {
      mostEfficientDevice = deviceEfficiency;
      lowestPowerDevice = deviceIterator;
    }
    ++powerIterator;
    ++performanceIterator;
    ++deviceIterator;
  }	  

  std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> result;
  std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>> resultEntry;
  get<0>(resultEntry) = mostEfficientDevice;
  get<1>(resultEntry) = this->neuralNetworkList;
  get<2>(resultEntry) = imageList;
  result.push_back(resultEntry);

  return result;
}

