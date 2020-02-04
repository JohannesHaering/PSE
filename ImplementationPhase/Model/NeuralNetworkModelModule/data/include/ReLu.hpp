#ifndef RELU_H_
#define RELU_H_
#include <vector>

#include "ActivationLayer.hpp"
//ActivationFunctions work on net[j], so a size does not need to be set on init

class ReLu : public ActivationLayer
{
	std::vector<float> fprop(std::vector<float> net);
	std::vector<float> bprop(std::vector<float> feedback);
};
#endif
