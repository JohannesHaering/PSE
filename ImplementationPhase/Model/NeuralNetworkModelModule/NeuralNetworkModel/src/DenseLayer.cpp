#include "DenseLayer.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DenseLayer::DenseLayer(int inputSize, int outputSize) : DenseLayer::DenseLayer(inputSize, outputSize, 0.01) {}

DenseLayer::DenseLayer(int inputSize, int outputSize, float learningRate) : inputSize(inputSize), outputSize(outputSize), learningRate(learningRate)
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
	std::uniform_real_distribution<float> distr(-r, r);

	for (int i = 0; i < inputSize; i++) {
		weights[i].resize(outputSize);
		for (int j = 0; j < outputSize; j++)
			weights[i][j] = distr(generator);
	}
	float sum = 0;
	for (int i = 0; i < inputSize; i++)
		for (int j = 0; j < outputSize; j++) sum += weights[i][j];
	std::cout << "init sum: " << sum << std::endl;
}

void DenseLayer::set_bias(std::vector<float> new_bias)
{
	bias = new_bias;
}

void DenseLayer::set_weights(std::vector<std::vector<float>> new_weights)
{
	weights = new_weights;
}

std::vector<std::vector<float>> DenseLayer::get_weights() { return weights; }

std::vector<float> DenseLayer::get_biase() { return bias; }

std::vector<float> DenseLayer::forward(std::vector<float> new_input)
{
	for (int j = 0; j < outputSize; j++) net[j] = bias[j];
	for (int i = 0; i < inputSize; i++)
	{
		input[i] = new_input[i]; //store input for backprop
		for (int j = 0; j < outputSize; j++)
			net[j] += weights[i][j] * input[i];
	}
	return net;
}

std::vector<float> DenseLayer::backprob(std::vector<float> feedback, float learningrate)
{
	//calc derivate for next Layers
	for (int input_i = 0; input_i < inputSize; input_i++) {
		double update = 0;
		for (int output_j = 0; output_j < outputSize; output_j++) {
			update += feedback[output_j] * weights[input_i][output_j];
		}
		backPropRes[input_i] = update;
	}

	//update weights	
	for (int input_i = 0; input_i < inputSize; input_i++)
		for (int output_j = 0; output_j < outputSize; output_j++)
		{
			double update = input[input_i] * feedback[output_j] * learningRate;
			weights[input_i][output_j] -= update;
		}

	//update bias
	for (int output_j = 0; output_j < weights[0].size(); output_j++)
		bias[output_j] -= 1 * feedback[output_j] * learningRate;

	return backPropRes;
}
