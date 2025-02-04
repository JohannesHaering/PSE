#include "ReLuLayer.hpp"
#include "ReLuLayerCPP.hpp"
#include "MatrixDefine.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init
ReLuLayer::ReLuLayer()
{
	layerType = LayerType::RELU;
	layerStrategy = new ReLuLayerCPP();
}


TENSOR(float) ReLuLayer::forward(TENSOR(float) net)
{
	this->net = net;
	output_forward = layerStrategy->forward(net);
	return output_forward;
}


TENSOR(float) ReLuLayer::backprob(TENSOR(float) feedback)
{
	output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

TENSOR(float) ReLuLayer::backprob(TENSOR(float) feedback, float learningrate)
{
	output_backward = layerStrategy->backprob(feedback);
	return output_backward;
}

void ReLuLayer::setMode(DeviceType device) {
    switch(device) {
    case DeviceType::CPP :
        layerStrategy = new ReLuLayerCPP();
        break;
    case DeviceType::CPU :
        break;
    }
}


