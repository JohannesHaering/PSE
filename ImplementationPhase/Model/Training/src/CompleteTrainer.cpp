#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
#include <iostream>
#include <cmath>

CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate, int batchSize) : neuralNetwork(neuralNetwork), learningRate(learningRate), batchSize(batchSize) 
{
  if (batchSize < 1) { std::cout <<"Error, batchSize < 1" << std::endl;}
  if (batchSize > 1) {
    std::cout << "updating batchSize from Layers to " << batchSize << std::endl;
	  NetworkLayer* lastlayer = neuralNetwork->getLastLayer();
    for (auto layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
    {
      layer->setBatchSize(batchSize);
      if (layer == lastlayer) break;
    }
  }
  std::cout << "finished batchSize update" << std::endl;

}




void CompleteTrainer::train(std::vector<float> target)
{
	std::vector<float> tmp = target;

  NetworkLayer* lastlayer = neuralNetwork->getLastLayer();
  for (auto layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
  {
		feedback = layer->backprob(target, learningRate);
		tmp = feedback;
    if (layer == lastlayer) break;
	}
	learningRate *= 0.99;
}


std::vector<float> CompleteTrainer::forward(std::vector<float> input)
{
	std::vector<float> tmp = input;

  NetworkLayer* lastlayer = neuralNetwork->getLastLayer();
  for (auto layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
  {
		output = layer->forward(input);
		tmp = output;
    if (layer == lastlayer) break;
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
