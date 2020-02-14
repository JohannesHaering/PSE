#include "LeakyReLuLayer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init

LeakyReLuLayer::LeakyReLuLayer()
{
  layerType = LayerType::LEAKYRELU;
}

std::vector<float> LeakyReLuLayer::forward(std::vector<float> net)
{
	output = std::vector<float>(net.size());
	for (int j = 0; j < net.size(); j++) output[j] = input[j] > 0 ? net[j] : 0.01*net[j];
	return output;
}


std::vector<float> LeakyReLuLayer::backprob(std::vector<float> feedback)
{
	std::vector<float> feedback_new(feedback.size());
	for (int output_j = 0; output_j < feedback.size(); output_j++) feedback_new[output_j] = (feedback[output_j] > 0 ? feedback[output_j] : 0.01*feedback[output_j]);
	return feedback_new;
}
