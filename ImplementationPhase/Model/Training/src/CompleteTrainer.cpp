#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
#include <iostream>
#include <cmath>
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 


CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate) : neuralNetwork(neuralNetwork), learningRate(learningRate) {}


void CompleteTrainer::train(std::vector<float> target)
{
	std::vector<float> tmp = target;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (auto layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer()) 
	{
		feedback = layer->backprob(target, learningRate);
		tmp = feedback;
	}
	learningRate *= 0.99;
}


std::vector<float> CompleteTrainer::forward(std::vector<float> input)
{
	std::vector<float> tmp = input;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (NetworkLayer* layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer())
	{
		output = layer->forward(input);
		tmp = output;
	}
	return output;
}


float CompleteTrainer::calcCEError(std::vector<float> target)
{
  if (target.size() != output.size()) {
    std::cout << "error, feedback and output size mismatch!" << std::endl; 
    return 42.0f;
  }
	float error = 0;
	for (int i = 0; i < output.size(); i++) error -= target[i] * output[i];
	return error;
}
