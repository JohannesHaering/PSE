#include <list>
#include <tuple>
#include "HighPerformanceMode.hpp"
#include "Device.hpp"

HighPerformanceMode::HighPerformanceMode() : Mode("HighPerformanceMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> HighPerformanceMode::getImageDistribution(std::list<cv::Mat> imageList)
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  int deviceAmount = deviceList.size();
  int imageAmount = imageList.size();
  int imagesPerDevice = imageAmount / deviceAmount; //take care of rounding
  int roundingError = imageAmount - imagesPerDevice;

  std::list<std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>> result;

  std::list<cv::Mat> imageAssignements;
  int startImage = 0;
  for (auto const& it : deviceList) //calculate images for each device
  {
    std::tuple<Device, std::list<NeuralNetworkAdapter>, std::list<cv::Mat>>* resultEntry;
    std::get<0>(*resultEntry) = it;
    std::get<1>(*resultEntry) = this->neuralNetworkList;
    int roundingErrorExists = 0;
    if (roundingError > 0) 
    {
      roundingError--;
      roundingErrorExists = 1;
    }
    auto startIterator = imageList.begin();
    for (int i = 0; i < startImage; i++) {
            ++startIterator;
    }
    auto endIterator  = startIterator;
    for (int i = 0; i < (imagesPerDevice + roundingErrorExists); i++) {
            ++endIterator;
    }
    std::get<2>(*resultEntry) = std::list<cv::Mat>(&*startIterator, &*endIterator);

    result.push_back(*resultEntry);
  }
  return result;
}

