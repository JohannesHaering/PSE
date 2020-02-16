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

MatrixDefine::TENSOR(float) DenseLayer::forward(MatrixDefine::TENSOR new_input)
{
  net = new_input;//store it for backprop
  for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
      output_forward[batchIteration][0][0] = bias;//deep copy?
      for (int i = 0; i < inputSize; i++)
      {
        for (int j = 0; j < outputSize; j++)
          output_forward[batchIteration][0][0][j] += weights[i][j] * net[batchIteration][0][0][i];
      }
      std::cout << "finished dense forward" << std::endl;
      return output_forward;
  }
}

MatrixDefine::TENSOR(float) DenseLayer::backprob(MatrixDefine::TENSOR(float) feedback, float learningrate)
{
  for (int batchIteration = 0; batchIteration < new_input.size(); batchIteration++) {
    std::vector<std::vector<float>> new_weights = weights;//deep copy?
    std::vector<float> new_bias = bias; //deep copy?

    //calc derivate for next Layers
    for (int input_i = 0; input_i < inputSize; input_i++) {
      double update = 0;
      for (int output_j = 0; output_j < outputSize; output_j++) {
        update += feedback[batchIteration][0][0][output_j] * weights[input_i][output_j];
      }
      output_backward[batchIteration][0][0][input_i] = update;
    }

    //update weights	
    double update;
    for (int input_i = 0; input_i < inputSize; input_i++)
    {
      for (int output_j = 0; output_j < outputSize; output_j++)
      {
        new_weights[input_i][output_j] -= net[batchIteration][0][0][input_i] * feedback[batchIteration][0][0][output_j] * learningRate;
      }
    }

    //update bias
    for (int output_j = 0; output_j < weights[0].size(); output_j++)
    {
      new_bias[output_j] -= feedback[batchIteration][0][0][output_j] * learningRate;
    }
    

    }
    weights = new_weights;
    bias = new_bias;
    return output_backward;
}
