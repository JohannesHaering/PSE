#include "ReLu.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init


std::vector<float> ReLu::fprop(std::vector<float> net)
{
	std::vector<float> output = std::vector<float>(net.size());
	for (int j = 0; j < net.size(); j++) output[j] = std::max(0.0f,net[j]);
	return output;
}


std::vector<float> ReLu::bprop(std::vector<float> feedback)
{
	std::vector<float> feedback_new(feedback.size());
	for (int output_j = 0; output_j < feedback.size(); output_j++) feedback_new[output_j] = (feedback[output_j] > 0 ? feedback[output_j] : 0);
	return feedback_new;
}
