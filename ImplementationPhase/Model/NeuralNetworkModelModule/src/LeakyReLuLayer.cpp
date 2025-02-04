#include "LeakyReLuLayer.hpp"
#include <vector>
#include "LeakyReLuLayerCPP.hpp"
#include "MatrixDefine.hpp"

//ActivationFunctions work on net[j], so a size does not need to be set on init
LeakyReLuLayer::LeakyReLuLayer()
{
  layerType = LayerType::LEAKYRELU;
  layerStrategy = new LeakyReLuLayerCPP();
}


TENSOR(float) LeakyReLuLayer::forward(TENSOR(float) net)
{
  this->net = net;
  output_forward = layerStrategy->forward(net);
	return output_forward;
}

TENSOR(float) LeakyReLuLayer::backprob(TENSOR(float) feedback)
{
  output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

TENSOR(float) LeakyReLuLayer::backprob(TENSOR(float) feedback, float learningRate)
{
	output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

void LeakyReLuLayer::setMode(DeviceType device) {
    switch(device) {
    case DeviceType::CPP :
        layerStrategy = new LeakyReLuLayerCPP();
        break;
    case DeviceType::CPU :
        break;
    }
}

