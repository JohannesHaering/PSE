#ifndef DENSELAYER_H_
#define DENSELAYER_H_

#include <string>
#include <math.h>
#include <vector>
#include "NetworkLayer.hpp"

class DenseLayer : public NetworkLayer
{
private: 
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
	DenseLayer(int inputSize, int outputSize);
	DenseLayer(int inputSize, int outputSize, float learningRate);
	void set_bias(std::vector<float> new_bias);
	void set_weights(std::vector<std::vector<float>> new_weights);
	std::vector<float> forward(std::vector<float> input_data);
	std::vector<float> backprob(std::vector<float> updates, float learningRate);
	std::vector<std::vector<float>> get_weights();
	std::vector<float> get_biase();
};
#endif

