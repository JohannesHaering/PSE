#include "fc_layer.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

fc_layer::fc_layer(int inputSize, int outputSize) : fc_layer::fc_layer(inputSize, outputSize, 0.01) {}

fc_layer::fc_layer(int inputSize, int outputSize, float learningRate) : inputSize(inputSize), outputSize(outputSize), learningRate(learningRate)
{
	bias = std::vector<float>(outputSize, 0.1);
	backPropRes = std::vector<float>(inputSize);
	input = std::vector<float>(inputSize);
	output = std::vector<float>(outputSize);
	net = std::vector<float>(outputSize);
	weights.resize(inputSize);
	float r = sqrt(12.0 / (inputSize + outputSize));
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

void fc_layer::set_bias(std::vector<float> new_bias) 
{
	bias = new_bias;
}

void fc_layer::set_weights(std::vector<std::vector<float>> new_weights)
{
	weights = new_weights;
}

std::vector<std::vector<float>> fc_layer::get_weights() {return weights;}

std::vector<float> fc_layer::get_biase() {return bias;}

std::vector<float> fc_layer::fprop(std::vector<float> new_input)
{
	for (int j = 0; j < outputSize; j++) net[j] = bias[j];
	for (int i = 0; i < inputSize; i++) 
	{
		input[i] = new_input[i]; //store input
		for (int j = 0; j < outputSize; j++)
			net[j] += weights[i][j] * input[i];
	}
	//ReLu
	//for (int j = 0; j < outputSize; j++) output[j] = std::max(0.0f,net[j]);
	
	//Leaky ReLu
	//for (int j = 0; j < outputSize; j++) output[j] = (net[j] > 0) ? net[j] : 0.01*net[j];

	//Sigmoid ?
	for (int j = 0; j < outputSize; j++) output[j] = 1 / (1 + exp (-1*net[j]));
	
	return output;
}



std::vector<float> fc_layer::bprop(std::vector<float> feedback, float learningrate)
{
	//Leaky ReLu
	//for (int output_j = 0; output_j < outputSize; output_j++) feedback[output_j] *= (net[output_j] > 0 ? 1 : 0.01);//checked
	//ReLu
	//for (int output_j = 0; output_j < outputSize; output_j++) feedback[output_j] *= (net[output_j] > 0 ? 1 : 0);//checked
	//Sigmoid
	for (int output_j = 0; output_j < outputSize; output_j++) feedback[output_j] *= (output[output_j] * (1 - output[output_j]));

	for (int input_i = 0; input_i < inputSize; input_i++) {
		double update = 0;
		for (int output_j = 0; output_j < outputSize; output_j++) {
			update += feedback[output_j] * weights[input_i][output_j]; //F'(net_j) from prev layer, not this one
		}
		backPropRes[input_i] = update;
	}
	
	//update weights	
	for (int input_i = 0; input_i < inputSize; input_i++)
		for (int output_j = 0; output_j < outputSize; output_j++) 
		{
			double update = input[input_i] * feedback[output_j] * learningRate; //checked
			weights[input_i][output_j] -= update;
		}
	
	//update bias
	for (int output_j = 0; output_j < weights[0].size(); output_j++) 
		bias[output_j] -= 1 * feedback[output_j] * learningRate;//checked

	std::cout << "learning rate now: " << learningRate << std::endl;
	return backPropRes;
}
