#include "SigmoidLayer.hpp"
#include "SigmoidLayerCPP.hpp"
#include <vector>
#include <cmath>

SigmoidLayer::SigmoidLayer()
{
  layerType = LayerType::SIGMOID;
  layerStrategy = SigmoidLayerCPP();
}

TENSOR(float)  SigmoidLayer::forward(TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy.forward(net);
	return output_forward;
}


TENSOR(float) SigmoidLayer::backprob(TENSOR(float) feedback)
{
  output_backward = layerStrategy.backprob(feedback);
	return output_backward;
}

void SigmoidLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = SigmoidLayerCPP();
  }
}

