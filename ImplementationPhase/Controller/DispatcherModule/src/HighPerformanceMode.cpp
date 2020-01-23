#include <list>
#include <tuple>
#include "HighPerformanceMode.hpp"
#include "Device.hpp"

HighPerformanceMode::HighPerformanceMode() : Mode("HighPerformanceMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> Mode::getImageDistribution(std::list<cv::mat> imageList) 
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  int deviceAmount = deviceList.size();
  int imageAmount = imageList.size();
  int imagesPerDevice = imageAmount / deviceAmount; //take care of rounding
  int roundingError = imageAmount - imagesPerDevice;

  std::list<std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>>> result;

  std::list<cv::Mat> imageAssignements;
  int startImage = 0;
  for (auto const& it : DeviceList) //calculate images for each device
  {
    std::tuple<Device, std::list<NeuralNetwork>, std::list<cv::Mat>> resultEntry;
    get<0>(resultEntry) = *it;
    get<1>(resultEntry) = this->neuralNetworkList;
    int roundingErrorExists = 0;
    if (roundingError > 0) 
    {
      roundingError--;
      roundingErrorExists = 1;
    }
    cv::mat *startIterator = imagelist.begin() + startImage;
    cv::mat *endIterator   = startIterator + imagesPerDevice + roudingErrorExists ;
    get<2>(resultEntry) = std::list<cv::mat>(startIterator, endIterator);

    result.push_back(resultEntry);
  }
  return result;
}

