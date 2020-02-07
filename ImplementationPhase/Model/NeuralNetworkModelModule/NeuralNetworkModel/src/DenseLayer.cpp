#include "DenseLayer.hpp"
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

  iterationInBatch = 0;
  batchSize = 1;
  inputStorageVector = std::vector<std::vector<float>>(batchSize);
  feedbackStorageVector = std::vector<std::vector<float>>(batchSize);
}

void DenseLayer::set_bias(std::vector<float> new_bias)
{
	bias = new_bias;
}

void DenseLayer::set_weights(std::vector<std::vector<float>> new_weights)
{
	weights = new_weights;
}

void DenseLayer::setBatchSize(int batchSize)
{
  std::cout << "batchSize" << batchSize <<std::endl;
  this->batchSize = batchSize;
  inputStorageVector = std::vector<std::vector<float>>(batchSize);
  feedbackStorageVector = std::vector<std::vector<float>>(batchSize);
  std::cout << "batchSize" << batchSize <<std::endl;
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
  std::cout << "finished dense forward" << std::endl;
	return net;
}





std::vector<float> DenseLayer::backprob(std::vector<float> feedback, float learningrate)
{
  iterationInBatch++; //to know when to update weights
  std::cout << "iterationInBatch: " << iterationInBatch << std::endl;
	//calc derivate for next Layers
	for (int input_i = 0; input_i < inputSize; input_i++) {
		double update = 0;
		for (int output_j = 0; output_j < outputSize; output_j++) {
			update += feedback[output_j] * weights[input_i][output_j];
		}
		backPropRes[input_i] = update;
	}

  if (iterationInBatch < batchSize) {
    //store input, output for later weight/bias update
    inputStorageVector[iterationInBatch] = input;
    feedbackStorageVector[iterationInBatch] = feedback;
    std::cout << "storing input and feedback. iteration: " << iterationInBatch << std::endl; 
    return backPropRes;
  }
  //update last vector entry and then process entire batch
  std::cout << "updating weights. iteration: " << iterationInBatch << std::endl;

	inputStorageVector.back() = input;
  feedbackStorageVector.back() = feedback;
  
  //update weights	
  double update;
	for (int input_i = 0; input_i < inputSize; input_i++)
  {
		for (int output_j = 0; output_j < outputSize; output_j++)
		{
      update = 0;
      for (int iteration = 0; iteration < batchSize; iteration++)
  			update += inputStorageVector[iteration][input_i] * feedbackStorageVector[iteration][output_j];
			weights[input_i][output_j] -= update * learningRate;
		}
  }

	//update bias
	for (int output_j = 0; output_j < weights[0].size(); output_j++)
  {
    update = 0;
    for (int iteration = 0; iteration < batchSize; iteration++)
      update = feedbackStorageVector[iteration][output_j];
		bias[output_j] -= update * learningRate;
  }

  iterationInBatch = 0; //reset counter (next batch from now on)
	return backPropRes;
}
