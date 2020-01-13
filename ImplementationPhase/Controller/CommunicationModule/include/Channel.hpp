#ifndef CHANNEL_H_
#define CHANNEL_H_
#include <list>

// Abstract class. Should be extended by device-type specific classes.
class Channel {
  PUBLIC:
    Channel(Device connectedDevice);
    Channel(Device connectedDevice, std::list<NeuralNetwork> neuralNetworkList);
    void setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList);
    std::list<Result> sendImageList(std::list imageList);

  PROTECTED:
    virtual void Channel::setNeuralNetworkList(std::list<NeuralNetwork> neuralNetworkList) = 0;
    

  PRIVATE:
    Device deviceHandler;
    std::list<NeuralNetworkAdapter> neuralNetworkList;
    std::list<cv::Mat> imageList;
