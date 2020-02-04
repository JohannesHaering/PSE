#ifndef SOFTMAX_H_
#define SOFTMAX_H_

#include <vector>
#include "ActivationLayer.hpp"

//ActivationFunctions work on net[j], so a size does not need to be set on init

class Softmax : public ActivationLayer
{
	public:
		std::vector<float> fprop(std::vector<float> net);
		std::vector<float> bprop(std::vector<float> target);
		float calcCEError();
	private:
		float error;
		std::vector<float> target;

};
#endif
