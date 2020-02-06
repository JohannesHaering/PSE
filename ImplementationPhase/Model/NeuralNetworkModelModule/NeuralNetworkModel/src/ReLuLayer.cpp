#include "ReLuLayer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init

std::vector<float> ReLuLayer::forward(std::vector<float> net)
{
	output = std::vector<float>(net.size());
	for (int j = 0; j < net.size(); j++) output[j] = input[j] > 0 ? net[j] : 0;
	return output;
}


std::vector<float> ReLuLayer::backprob(std::vector<float> feedback)
{
	std::vector<float> feedback_new(feedback.size());
	for (int output_j = 0; output_j < feedback.size(); output_j++) feedback_new[output_j] = (feedback[output_j] > 0 ? feedback[output_j] : 0);
	return feedback_new;
}
