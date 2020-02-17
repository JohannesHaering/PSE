#include "SoftmaxLayer.hpp"
#include "SoftmaxLayerCPP.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <cmath>

//ActivationFunctions work on net[j], so a size does not need to be set on init

SoftmaxLayer::SoftmaxLayer()
{
  layerType = LayerType::SOFTMAX;
  layerStrategy = new SoftmaxLayerCPP();
}

TENSOR(float) SoftmaxLayer::forward(TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy->forward(net);
  return output_forward;
}

std::vector<float> SoftmaxLayer::calcCEError(TENSOR(float) target) //uses labels, output and currentSize 
{
  std::vector<float> result = std::vector<float>(target.size(), 0.0);
  for (int b = 0; b < target.size(); b++) {
  	for (int i = 0; i < output_forward.size(); i++) {
      result[b] -= target[b][0][0][i] * log(output_forward[b][0][0][i]);
    }
  }
	return result;
}

TENSOR(float) SoftmaxLayer::backprob(TENSOR(float) feedback)
{
  output_backward = layerStrategy->backprob(feedback, output_forward);
	return output_backward;
}

void SoftmaxLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = new SoftmaxLayerCPP();
  }
}
