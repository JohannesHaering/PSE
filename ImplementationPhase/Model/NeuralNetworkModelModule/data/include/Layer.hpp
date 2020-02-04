#ifndef LAYER_H_
#define LAYER_H_
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init

class Layer
{
	protected:
		std::vector<float> input;
		std::vector<float> output;
	public:
		virtual std::vector<float> fprop(std::vector<float> net) = 0;
		virtual std::vector<float> bprop(std::vector<float> feedback, float learningRate) = 0;

};
#endif
