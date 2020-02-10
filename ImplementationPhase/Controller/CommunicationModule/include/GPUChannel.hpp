#ifndef GPU_CHANNEL_H_
#define GPU_CHANNEL_H_
#include <list>

#include <opencv2/opencv.hpp>

#include "NeuralNetworkAdapter.hpp"
#include "Result.hpp"
#include "Device.hpp"


// Abstract class. Should be extended by device-type specific classes.
class GPUChannel {
  public:
    GPUChannel(Device connectedDevice);
    GPUChannel(Device connectedDevice, std::list<NeuralNetworkAdapter> neuralNetworkList);
    //void setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList);
    std::list<Result> sendImageList(std::list<cv::Mat> imageList);

  protected:
    void setNeuralNetworkList(std::list<NeuralNetworkAdapter> neuralNetworkList);
    

  private:
    Device deviceHandler;
    std::list<NeuralNetworkAdapter> neuralNetworkList;
    std::list<cv::Mat> imageList;
};
#endif
