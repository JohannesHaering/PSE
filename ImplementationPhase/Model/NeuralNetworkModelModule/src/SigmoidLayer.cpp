#include "SigmoidLayer.hpp"
#include "Activation.hpp"
#include <vector>
#include <cmath>

SigmoidLayer::SigmoidLayer()
{
  layerType = LayerType::SIGMOID;
  activationType = Activation::SIGMOID;
}

std::vector<float>  SigmoidLayer::forward(std::vector<float> net)
{
	output = std::vector<float>(net.size());
	for (int j = 0; j < net.size(); j++) output[j] = 1 / (1 + exp (-1*net[j]));
	return output;
}


std::vector<float> SigmoidLayer::backprob(std::vector<float> feedback)
{
	std::vector<float> feedback_new(feedback.size());
	for (int output_j = 0; output_j < feedback.size(); output_j++) feedback_new[output_j] = (feedback[output_j] * (1 - feedback[output_j]));
	return feedback_new;
}
