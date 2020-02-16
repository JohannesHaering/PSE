#include "DenseLayer.hpp"
#include "DenseLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DenseLayer::DenseLayer(int inputSize, int outputSize) : DenseLayer::DenseLayer(inputSize, outputSize, 0.01) {}

DenseLayer::DenseLayer(int inputSize, int outputSize, float learningRate) : inputSize(inputSize), outputSize(outputSize), learningRate(learningRate)
{
  	layerType = LayerType::DENSE;
	bias = std::vector<float>(outputSize, 0.1);
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

	layerStrategy = DenseLayerCPP(this, inputSize, outputSize);
}

void DenseLayer::set_bias(std::vector<float> new_bias)
{
	bias = new_bias;
}

void DenseLayer::set_weights(std::vector<std::vector<float>> new_weights)
{
	weights = new_weights;
}

std::vector<std::vector<float>> DenseLayer::get_weights() 
{ 
  return weights; 
}

std::vector<float> DenseLayer::get_biase() 
{ 
  return bias; 
}

TENSOR(float) DenseLayer::forward(TENSOR new_input)
{
  net = new_input;//store it for backprop
  output_forward = layerStrategy.forward(new_input);
  return output_forward;
}

TENSOR(float) DenseLayer::backprob(TENSOR(float) feedback, float learningrate)
{
  output_backward = layerStrategy.backward(feedback, learningrate, net); 
  return output_backward;
}

void DenseLayer::setMode(DeviceType device, cl_int deviceID) {
  if (device == DeviceType::CPP) {
    layerStrategy = DenseLayerCPP(&weights, &bias, &learningRate, &inputSize, &outputSize);
  }
}
