#include "Softmax.hpp"
#include <vector>
#include <cmath>

//ActivationFunctions work on net[j], so a size does not need to be set on init


std::vector<float> Softmax::fprop(std::vector<float> net)
{
	output = std::vector<float>(net.size());
	
	float sum = 0;
	for (int j = 0; j < net.size(); j++) sum += exp(net[j]);
	for (int j = 0; j < net.size(); j++) output[j] = exp(1*net[j]) / sum;
	return output;
}

float Softmax::calcCEError() //uses labels, output and currentSize 
{
	error = 0;
	for (int i = 0; i < output.size(); i++) error -= target[i] * log(output[i]);
	return error;
}

std::vector<float> Softmax::bprop(std::vector<float> target)
{
	this->target = target;
	std::vector<float> feedback_new(target.size());
	for (int output_j = 0; output_j < target.size(); output_j++) feedback_new[output_j] = output[output_j] - target[output_j];
	return feedback_new;
}
