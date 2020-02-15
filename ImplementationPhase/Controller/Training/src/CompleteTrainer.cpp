#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "LayerType.hpp"

CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate, int batchSize) : neuralNetwork(neuralNetwork), learningRate(learningRate), batchSize(batchSize) 
{
}

TENSOR(float) CompleteTrainer::forward(TENSOR(float) input)
{
	TENSOR(float) tmp = input;

  for (NetworkLayer *layer = neuralNetwork->begin(); layer != neuralNetwork->end(); layer++)
  {
    //std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		output = layer->forward(tmp);
    //std::cout << "layertype: " << layer->getLayerType() << std::endl;
    //std::cout << "output size: " << output.size() << std::endl;
		tmp = output;
	}
  std::cout << "returning from forward" << std::endl;
	return output;
}

void CompleteTrainer::train(TENSOR(float) target)
{
  std::cout << std::endl << "train in completeTrainer " <<std::endl;
	TENSOR(float) tmp = target;
  for (NetworkLayer *layer = neuralNetwork->rbegin(); layer != neuralNetwork->rend(); layer++)
  {
    //std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		feedback = layer->backprob(tmp, learningRate);
    //std::cout << "layertype: " << layer->getLayerType() << std::endl;
    //std::cout << "feedback size: " << feedback.size() << std::endl;
		tmp = feedback;
	}
	learningRate *= 0.99;
  std::cout << "returning from train" << std::endl;
}

TENSOR(float) CompleteTrainer::calcCEError(TENSOR(float) target)
{
  if (target.size() != output.size()) {
    std::cout << "error, batchsize of target Tensor and output Tensor mismatch! target vs output : " << target.size() << " " << output.size() << std::endl; 
    return 42.0f;
  }
  TENSOR(float) result = TENSOR(float)(target.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(1, 0.0f))));
  for (int b = 0; b < target.size(); b++)
  {
	  for (int i = 0; i < target[0][0][0].size(); i++)
    {
      result[b][0][0][0] -= target[b][0][0][i] * output[b][0][0][i];
    }
  }
	return result;
}
