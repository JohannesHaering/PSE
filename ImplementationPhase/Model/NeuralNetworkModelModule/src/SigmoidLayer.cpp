#include "SigmoidLayer.hpp"
#include "SigmoidLayerCPP.hpp"
#include <vector>
#include <cmath>

SigmoidLayer::SigmoidLayer()
{
  layerType = LayerType::SIGMOID;
  layerStrategy = SigmoidLayerCPP();
}

MatrixDefine::TENSOR(float)  SigmoidLayer::forward(MatrixDefine::TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy.forward(net);
	return output_forward;
}


MatrixDefine::TENSOR(float) SigmoidLayer::backprob(MatrixDefine::TENSOR(float) feedback)
{
  output_backward = layerStrategy.backprob(feedback);
	return output_backward;
}

void SigmoidLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = SigmoidLayerCPP();
  }
}
