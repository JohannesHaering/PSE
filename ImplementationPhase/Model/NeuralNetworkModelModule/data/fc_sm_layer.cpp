#include "fc_sm_layer.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

fc_sm_layer::fc_sm_layer(int inputSize, int outputSize) : fc_sm_layer::fc_sm_layer(inputSize, outputSize, 0.01) {}

fc_sm_layer::fc_sm_layer(int inputSize, int outputSize, float learningRate) : inputSize(inputSize), outputSize(outputSize), learningRate(learningRate)
{
	bias = std::vector<float>(outputSize, 0.1);
	backPropRes = std::vector<float>(inputSize);
	input = std::vector<float>(inputSize);
	output = std::vector<float>(outputSize);
	net = std::vector<float>(outputSize);
	weights.resize(inputSize);
	
	//weight init
	float r = sqrt(12.0 / (inputSize + outputSize));//RELU
	//float r = 4 * sqrt(6.0 / (inputSize + outputSize));
	std::random_device rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_real_distribution<float> distr(-r,r);

	for (int i = 0; i < inputSize; i++) {
		weights[i].resize(outputSize);
		for (int j = 0; j < outputSize; j++)
			weights[i][j] =	distr(generator);
	}
	float sum = 0;
	for (int i = 0; i < inputSize; i++)
		for (int j = 0; j < outputSize; j++) sum += weights[i][j];
	std::cout << "init sum: " << sum << std::endl;
}

void fc_sm_layer::set_bias(std::vector<float> new_bias) 
{
	bias = new_bias;
}

void fc_sm_layer::set_weights(std::vector<std::vector<float>> new_weights)
{
	weights = new_weights;
	//weights = std::vector<float>(new_weights);
}

std::vector<std::vector<float>> fc_sm_layer::get_weights() {return weights;}

std::vector<float> fc_sm_layer::get_biase() {return bias;}

float fc_sm_layer::get_error() {return error;}

float fc_sm_layer::calcCEError() //uses labels, output and currentSize 
{
	error = 0;
	for (int i = 0; i < outputSize; i++) error -= target[i] * log(output[i]);
	return error;
}

std::vector<float> fc_sm_layer::fprop(std::vector<float> new_input)
{
	for (int j = 0; j < outputSize; j++) net[j] = bias[j];
	//std::cout << "printing sm input: ";
	for (int i = 0; i < inputSize; i++) 
	{
		input[i] = new_input[i]; //store input
		//std::cout << input[i] << " ";
		for (int j = 0; j < outputSize; j++)
			net[j] += weights[i][j] * input[i];
	}
	//std::cout << std::endl;
	float sum = 0;
	for (int j = 0; j < outputSize; j++) sum += exp(net[j]);
	for (int j = 0; j < outputSize; j++) output[j] = exp(1*net[j]) / sum;
	return output;
}



std::vector<float> fc_sm_layer::bprop(std::vector<int> new_target, float learningrate)
{
	target = std::vector<int>(new_target);
	std::vector<float> backProp_last = std::vector<float>(outputSize);
	std::vector<std::vector<float>> backProp_weights = std::vector<std::vector<float>>(inputSize,std::vector<float>(outputSize));
	std::vector<float> backProp_first = std::vector<float>(inputSize);
	for (int output_j = 0; output_j < outputSize; output_j++) backProp_last[output_j] = output[output_j] - target[output_j];
	for (int input_i = 0; input_i < inputSize; input_i++) 
		for (int output_j = 0; output_j < outputSize; output_j++)
			backProp_first[input_i] += backProp_last[output_j] * weights[input_i][output_j];
	
	//update weights	
	for (int input_i = 0; input_i < inputSize; input_i++)
		for (int output_j = 0; output_j < outputSize; output_j++) 
		{
			double update = input[input_i] * backProp_last[output_j] * learningRate;
			weights[input_i][output_j] -= update;
		}
	
	//update bias
	for (int output_j = 0; output_j < weights[0].size(); output_j++) 
		bias[output_j] -= 1 * backProp_last[output_j] * learningRate;

	std::cout << "learning rate now: " << learningRate << std::endl;
	return backProp_first;
}
