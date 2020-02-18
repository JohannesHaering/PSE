#include "CompleteTrainer.hpp"
#include "NetworkLayer.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include "LayerType.hpp"
#include "MatrixDefine.hpp"

CompleteTrainer::CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate) : neuralNetwork(neuralNetwork), learningRate(learningRate) {}

TENSOR(float) CompleteTrainer::forward(TENSOR(float) input)
{
	TENSOR(float) tmp = input;

  for (std::list<NetworkLayer*>::iterator layer = neuralNetwork->begin(); layer != neuralNetwork->end(); layer++)
  {
    //std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		output =(*layer)->forward(tmp);
    //std::cout << "layertype: " << layer->getLayerType() << std::endl;
    //std::cout << "output size: " << output.size() << std::endl;
		tmp = output;
	}
  std::cout << "returning from forward" << std::endl;
//    for (int z = 0; z < tmp[0].size(); z++)
  //    for (int y = 0; y < tmp[0][0].size(); y++)
    //    for (int x = 0; x < tmp[0][0][0].size(); x++)
      //    std::cout << tmp[0][z][y][x] << std::endl;
	return output;
}

void CompleteTrainer::train(TENSOR(float) target)
{
  std::cout << std::endl << "train in completeTrainer " <<std::endl;
	TENSOR(float) tmp = target;
  for (std::list<NetworkLayer*>::reverse_iterator layer = neuralNetwork->rbegin(); layer != neuralNetwork->rend(); layer++)
  {
    //std::cout << "layer: " << i++ << "input size: " << tmp.size() << std::endl;
		feedback = (*layer)->backprob(tmp, learningRate);
    //std::cout << "layertype: " << (*layer)->getLayerType() << std::endl;
    //std::cout << "feedback size: " << feedback.size() << std::endl;
		tmp = feedback;
	}
	learningRate *= 0.99;
  std::cout << "returning from train" << std::endl;
}

TENSOR(float) CompleteTrainer::calcCEError(TENSOR(float) target)
{
  TENSOR(float) result = TENSOR(float)(target.size(), MATRIX_3D(float)(1, MATRIX_2D(float)(1, std::vector<float>(1, 0.0f))));
  if (target.size() != output.size()) {
    std::cout << "error, batchsize of target Tensor and output Tensor mismatch! target vs output : " << target.size() << " " << output.size() << std::endl;

    result[0][0][0][0]=0.0f;
    return result;
  }
  for (int b = 0; b < target.size(); b++)
  {
	  for (int i = 0; i < target[0][0][0].size(); i++)
    {
      result[b][0][0][0] -= target[b][0][0][i] * output[b][0][0][i];
    }
  }
	return result;
}
