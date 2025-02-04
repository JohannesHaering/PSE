#include "SigmoidLayer.hpp"
#include "SigmoidLayerCPP.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <cmath>

SigmoidLayer::SigmoidLayer()
{
	layerType = LayerType::SIGMOID;
	layerStrategy = new SigmoidLayerCPP();
}

TENSOR(float)  SigmoidLayer::forward(TENSOR(float) net)
{
	this->net = net;
	output_forward = layerStrategy->forward(net);
	return output_forward;
}

TENSOR(float) SigmoidLayer::backprob(TENSOR(float) feedback)
{
	output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

TENSOR(float) SigmoidLayer::backprob(TENSOR(float) feedback, float learningrate)
{
	output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

void SigmoidLayer::setMode(DeviceType device) {
    switch(device) {
    case DeviceType::CPP :
        layerStrategy = new SigmoidLayerCPP();
        break;
    case DeviceType::CPU :
        break;
    }
}

