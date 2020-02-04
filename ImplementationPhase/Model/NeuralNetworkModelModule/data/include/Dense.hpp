#ifndef _Dense_H_
#define _Dense_H_
#include <math.h>
#include <vector>
#include "Layer.hpp"

class Dense : public Layer
{
	std::vector<float> bias;
	float learningRate;
	int inputSize;
	int outputSize;
	std::vector<std::vector<float>> weights;
	std::vector<float> net;
	std::vector<float> input;
	std::vector<float> output;
	std::vector<float> backPropRes;
	public: 
		Dense(int inputSize, int outputSize);
		Dense(int inputSize, int outputSize, float learningRate);
		void set_bias(std::vector<float> new_bias);
		void set_weights(std::vector<std::vector<float>> new_weights);
		std::vector<float> fprop(std::vector<float> input_data);
		std::vector<float> bprop(std::vector<float> updates, float learningRate);			
		std::vector<std::vector<float>> get_weights();
		std::vector<float> get_biase();
};
#endif
