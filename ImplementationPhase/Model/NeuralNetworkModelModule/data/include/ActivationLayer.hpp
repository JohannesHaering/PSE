#ifndef ActivationLAYER_H_
#define ActivationLAYER_H_
#include <vector>
#include "Layer.hpp"

//ActivationFunctions work on net[j], so a size does not need to be set on init

class ActivationLayer : public Layer
{
	protected:
		virtual std::vector<float> bprop(std::vector<float> feedback) = 0;
		std::vector<float> bprop(std::vector<float> feedback, float learningRate);

};
#endif
