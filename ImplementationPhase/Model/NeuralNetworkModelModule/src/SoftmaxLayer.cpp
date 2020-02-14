#include "SoftmaxLayer.hpp"
#include <vector>
#include <cmath>

//ActivationFunctions work on net[j], so a size does not need to be set on init

SoftmaxLayer::SoftmaxLayer()
{
  layerType = LayerType::SOFTMAX;
}



MatrixDefine::TENSOR(float) SoftmaxLayer::forward(MatrixDefine::TENSOR(float) net)
{
  this->net = net;
  output_forward = net;
	
  float sum = 0;
  for (int b = 0; b < net.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 sum += exp(net[b][z][y][x]);
	

  for (int b = 0; b < net.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 output_forward[b][z][y][x] = exp(net[b][z][y][x]) / sum ;
  
  return output_forward;
}

std::vector<float> SoftmaxLayer::calcCEError(MatrixDefine::TENSOR(float) target) //uses labels, output and currentSize 
{
  std::vector<float> result = std::vector<float>(target.size(), 0.0);
  for (int b = 0; b < target.size(); b++) {
  	for (int i = 0; i < output_forward.size(); i++) {
      result[b] -= target[b][0][0][i] * log(output_forward[b][0][0][i]);
    }
  }
	return result;
}

MatrixDefine::TENSOR(float) SoftmaxLayer::backprob(MatrixDefine::TENSOR(float) feedback)
{
  output_backward = feedback;
  
  for (int b = 0; b < feedback.size(); b++)
      for (int z = 0; z < feedback[0].size(); z++)
          for (int y = 0; y < feedback[0][0].size(); y++)
              for (int x = 0; x < feedback[0][0][0].size(); x++)
                 output_backward[b][z][y][x] =  output_forward[b][z][y][x] - feedback[b][z][y][x];

	return output_backward;
}
