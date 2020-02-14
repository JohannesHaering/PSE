#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "LayerType.hpp"

CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate, int batchSize) : neuralNetwork(neuralNetwork), learningRate(learningRate), batchSize(batchSize) 
{
  if (batchSize < 1) { std::cout <<"Error, batchSize < 1" << std::endl;}
  if (batchSize > 1) {
    std::cout << "updating batchSize from Layers to " << batchSize << std::endl;
	  NetworkLayer* lastlayer = neuralNetwork->getLastLayer();
    for (auto layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
    {
      if (layer->getLayerType() == LayerType::DENSE)
        ((DenseLayer*) layer)->setBatchSize(batchSize);
      if (layer == lastlayer) break;
    }
  }
  std::cout << "finished batchSize update" << std::endl;
}


std::vector<float> CompleteTrainer::forward(std::vector<float> input)
{
	std::vector<float> tmp = input;

  int i = 0;
  NetworkLayer *lastLayer = neuralNetwork->getLastLayer();
  //for (auto& layer = neuralNetwork->begin(); layer != neuralNetwork->end(); layer++)
  for (NetworkLayer *layer = neuralNetwork->getFirstLayer();; layer = neuralNetwork->getNextLayer())
  {
    std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		output = layer->forward(tmp);
    std::cout << "layertype: " << layer->getLayerType() << std::endl;
    std::cout << "output size: " << output.size() << std::endl;
		tmp = output;
    if (layer == lastLayer) break;
	}
  std::cout << "returning from forward" << std::endl;
	return output;
}


void CompleteTrainer::train(std::vector<float> target)
{
  std::cout << std::endl << "train in completeTrainer " <<std::endl;
	std::vector<float> tmp = target;
  int i = 0;
  auto preFirst = neuralNetwork->begin();
  preFirst--;
  //for (auto& layer = neuralNetwork->end(); layer != preFirst ; layer--)
  for (NetworkLayer *layer = neuralNetwork->getLastLayer();; layer = neuralNetwork->getPreviousLayer())
  {
    std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		feedback = layer->backprob(tmp, learningRate);
    std::cout << "layertype: " << layer->getLayerType() << std::endl;
    std::cout << "feedback size: " << feedback.size() << std::endl;
		tmp = feedback;
    //if (layer == firstLayer) break;
	}
	learningRate *= 0.99;
  std::cout << "returning from train" << std::endl;
}

float CompleteTrainer::calcCEError(std::vector<float> target)
{
  if (target.size() != output.size()) {
    std::cout << "error, feedback and output size mismatch! target vs output : " << target.size() << " " << output.size() << std::endl; 
    return 42.0f;
  }
	float error = 0;
	for (int i = 0; i < output.size(); i++) error -= target[i] * output[i];
	return error;
}
