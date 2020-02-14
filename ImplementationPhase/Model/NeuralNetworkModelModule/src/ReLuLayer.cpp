#include "ReLuLayer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init
ReLuLayer::ReLuLayer()
{
  layerType = LayerType::RELU;
  layerStrategy = ReLuLayerCPP();
}


MatrixDefine::TENSOR(float) ReLuLayer::forward(MatrixDefine::TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy.forward(net);
	return output_forward;
}


MatrixDefine::TENSOR(float) ReLuLayer::backprob(MatrixDefine::TENSOR(float) feedback)
{
  output_backward = layerStrategy.forward(feedback);
	return output_backward;
}

void ReLuLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = ReLuLayerCPP();
  }
}
