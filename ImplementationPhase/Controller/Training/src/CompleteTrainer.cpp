#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 


CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate) : neuralNetwork(neuralNetwork), learningRate(learningRate) {}


void CompleteTrainer::train(std::vector<float> target)
{
	std::vector<float> output;
	std::vector<float> tmp = target;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (auto layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer()) 
	{
		output = layer->backprob(target, learningRate);
		tmp = output;
	}
	learningRate *= 0.99;
}


std::vector<float> CompleteTrainer::forward(std::vector<float> input)
{
	std::vector<float> tmp = input;
	std::vector<float> output;
	NetworkLayer* lastlayer = neuralNetwork->getLastLayer();

	for (NetworkLayer* layer = neuralNetwork->getFirstLayer(); layer != lastlayer; layer = neuralNetwork->getNextLayer())
	{
		output = layer->forward(input);
		tmp = output;
	}
	return output;
}
