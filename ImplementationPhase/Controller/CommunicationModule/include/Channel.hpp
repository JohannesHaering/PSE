#ifndef CHANNEL_H_
#define CHANNEL_H_
#include <list>

#include <opencv2/opencv.hpp>

#include "NeuralNetworkAdapter.hpp"
#include "Result.hpp"
#include "Device"


// Abstract class. Should be extended by device-type specific classes.
class Channel {
  PUBLIC:
    Channel(Device connectedDevice);
    Channel(Device connectedDevice, std::list<NeuralNetworkAdapter> neuralNetworkList);
    void setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList);
    std::list<Result> sendImageList(std::list imageList);

  PROTECTED:
    virtual void Channel::setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList) = 0;
    

  PRIVATE:
    Device deviceHandler;
    std::list<NeuralNetworkAdapter> neuralNetworkList;
    std::list<cv::Mat> imageList;
};
#endif
