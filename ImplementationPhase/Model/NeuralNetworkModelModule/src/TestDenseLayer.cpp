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

	layerStrategy = new DenseLayerCPP(this, inputSize, outputSize);
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

TENSOR(float) DenseLayer::forward(TENSOR(float) input_data)
{
    net = input_data;
    output_forward = TENSOR(float)(input_data.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(outputSize))));
    for (int batchIteration = 0; batchIteration < input_data.size(); batchIteration++) {
        output_forward[batchIteration][0][0] = bias;//deep copy?
        for (int i = 0; i < inputSize; i++)
        {
            for (int j = 0; j < outputSize; j++)
                output_forward[batchIteration][0][0][j] += weights[i][j] * input_data[batchIteration][0][0][i];
        }
    }
    return output_forward;
}

void print_weights(MATRIX_2D(float) tensor)
{
  for ( int y = 0; y < tensor.size(); y++)
  {
    for( int x = 0; x < tensor[0].size(); x++)
    {
      std::cout << tensor[y][x] << " ";
    }
    std::cout << std::endl;
  }

}

TENSOR(float) DenseLayer::backprob(TENSOR(float) updates, float learningrate)
{
//    print_weights(weights);
  
    output_backward = TENSOR(float)(updates.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(inputSize))));

    for (int batchIteration = 0; batchIteration < updates.size(); batchIteration++) {
        //calc derivate for next Layers
        for (int input_i = 0; input_i < inputSize; input_i++) {
            double update = 0;
            for (int output_j = 0; output_j < outputSize; output_j++) {
                update += updates[batchIteration][0][0][output_j] * weights[input_i][output_j];
            }
            output_backward[batchIteration][0][0][input_i] = update;
        }

        //update weights	
        double update;
        for (int input_i = 0; input_i < inputSize; input_i++) {
            for (int output_j = 0; output_j < outputSize; output_j++) {
                weights[input_i][output_j] -= net[batchIteration][0][0][input_i] * updates[batchIteration][0][0][output_j] * learningRate;
            }
        }

        //update bias
        for (int output_j = 0; output_j < weights[0].size(); output_j++) {
            bias[output_j] -= updates[batchIteration][0][0][output_j] * learningRate;
        }       
    }
  //  print_weights(weights);

    return output_backward;
}

void DenseLayer::setMode(DeviceType device, cl_int deviceID) {
}
