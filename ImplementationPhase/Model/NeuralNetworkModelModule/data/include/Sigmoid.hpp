#ifndef SIGMOID_H_
#define SIGMOID_H_
#include <vector>

#include "ActivationLayer.hpp"

//ActivationFunctions work on net[j], so a size does not need to be set on init

class Sigmoid : public Layer
{

	std::vector<float> fprop(std::vector<float> net);
	std::vector<float> bprop(std::vector<float> feedback);

};
#endif

