#ifndef _FC_SM_LAYER_H_
#define _FC_SM_LAYER_H_
#include <math.h>
#include <vector>

class fc_sm_layer
{
	float error;
	std::vector<float> bias;
	float learningRate;
	int inputSize;
	int outputSize;
	std::vector<std::vector<float>> weights;
	std::vector<float> net;
	std::vector<float> input;
	std::vector<float> output;
	std::vector<float> backPropRes;
	std::vector<int> target;
	public: 
		fc_sm_layer(int inputSize, int outputSize);
		fc_sm_layer(int inputSize, int outputSize, float learningRate);
		void set_bias(std::vector<float> new_bias);
		void set_weights(std::vector<std::vector<float>> new_weights);
		std::vector<float> fprop(std::vector<float> input_data);
		std::vector<float> bprop(std::vector<int> target, float learningRate);			
		std::vector<std::vector<float>> get_weights();
		std::vector<float> get_biase();
		float get_error();
		float calcCEError(); //uses labels, output and length 
};
#endif
