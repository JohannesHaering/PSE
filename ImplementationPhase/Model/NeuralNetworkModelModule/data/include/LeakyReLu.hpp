#ifndef _LEAKY_RELU_H_
#define _LEAKY_RELU_H_
#include <vector>
#include "ActivationLayer.hpp"

//ActivationFunctions work on net[j], so a size does not need to be set on init

class LeakyReLu : public ActivationLayer
{

	std::vector<float> fprop(std::vector<float> net);
	std::vector<float> bprop(std::vector<float> feedback);

};
#endif
