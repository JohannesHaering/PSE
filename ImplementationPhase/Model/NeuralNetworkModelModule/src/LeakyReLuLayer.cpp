#include "LeakyReLuLayer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init
LeakyReLuLayer::LeakyReLuLayer()
{
  layerType = LayerType::RELU;
  layerStrategy = LeakyReLuLayerCPP();
}


TENSOR(float) LeakyReLuLayer::forward(TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy.forward(net);
	return output_forward;
}


TENSOR(float) LeakyReLuLayer::backprob(TENSOR(float) feedback)
{
  output_backward = layerStrategy.forward(feedback);
	return output_backward;
}

void LeakyReLuLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = LeakyReLuLayerCPP();
  }
}

