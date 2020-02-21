#include <list>
#include <vector>
#include <tuple>
#include "HighPerformanceMode.hpp"
#include "Device.hpp"
#include "ImageFacade.hpp"
#include "DeviceType.hpp"

HighPerformanceMode::HighPerformanceMode() : Mode("HighPerformanceMode") {}

//Basic implementation, assignes (if possible) equal amount of img to each Device.
//Each Device has to run all NeuralNetworks on each image.
//Can be vastly improved
std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> HighPerformanceMode::getImageDistribution(std::list<std::string> imageList)
{
  std::list<Device> deviceList = this->getAllowedDeviceList();
  if (deviceList.size() == 0)
    return getTrivialDistribution(imageList);
  int deviceAmount = deviceList.size();
  std::cout << deviceAmount << std::endl;
  int imageAmount = imageList.size();
  int imagesPerDevice = imageAmount / deviceAmount; //take care of rounding
  int roundingError = imageAmount - imagesPerDevice * deviceAmount;

  std::list<std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float), std::vector<std::string>>> result;

  std::list<cv::Mat> imageAssignements;
  int startImage = 0;
  for (auto it : deviceList) //calculate images for each device
  {
    for (auto  nnit : neuralNetworkList) {
      std::tuple<DeviceType, NeuralNetworkAdapter, TENSOR(float)>* resultEntry;
      //std::get<0>(*resultEntry) = new Device(it.getType(), it.getName(), 10,10);
      //std::get<1>(*resultEntry) = nnit;
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
      std::list<std::string> assignedImageList = std::list<std::string>(startIterator, endIterator);

      std::vector<std::string> dirVector = std::vector<std::string>(assignedImageList.begin(), assignedImageList.end());

      std::list<cv::Mat> matList = ImageFacade().getImages(assignedImageList, nnit.getWidth(), nnit.getHeight(),nnit.getChannels());
      std::vector<cv::Mat> matVec = std::vector<cv::Mat>(matList.begin(), matList.end());
      TENSOR(float) tens = ImageFacade().createImageTensor(matVec, nnit.getWidth(), nnit.getHeight());
      
      std::string dev = it.getType();
      DeviceType type;
      if (dev.compare("CPU") == 0){
        type = DeviceType::CPU;
      } 
      else if (dev.compare("ASIC") == 0) {
        type = DeviceType::ASIC;
      } else {
        type = DeviceType::CPP; 
      }
      auto res = std::make_tuple(type, nnit, tens, dirVector);
      result.push_back(res);
    }
  }
  return result;
}

