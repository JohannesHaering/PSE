#include "SoftmaxLayer.hpp"
#include "SoftmaxLayerCPP.hpp"
#include "SoftmaxLayerASIC.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <cmath>
#include <iostream>

//ActivationFunctions work on net[j], so a size does not need to be set on init

SoftmaxLayer::SoftmaxLayer()
{
  layerType = LayerType::SOFTMAX;
  layerStrategy = new SoftmaxLayerCPP();
}

void SoftmaxLayer::calcMaxVec(std::vector<float> *maxVec)
{
  for (int b = 0; b < net.size(); b++)
  { 
      (*maxVec)[b] = net[b][0][0][0]; //def value
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
              {
                if ( net[b][z][y][x] > (*maxVec)[b]) (*maxVec)[b] = net[b][z][y][x];
              }
  }
}

TENSOR(float) SoftmaxLayer::forward(TENSOR(float) input_data)
{
    this->net = input_data;
 
    output_forward = input_data;
    std::vector<float> sum = std::vector<float>(input_data.size(), 0.0f);
    std::vector<float> max = std::vector<float>(input_data.size());
    calcMaxVec(&max);
    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                    sum[b] += exp(input_data[b][z][y][x] - max[b]);
    std::cout << "SoftmaxLayer: sum: 0 " << sum[0] << std::endl;   

    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                {
                  output_forward[b][z][y][x] = exp(input_data[b][z][y][x] - max[b]) / sum[b] ;
                }
    return output_forward;
 
}

//MSE instead of CE Error, due to issues from stephis gui. Not renamed due to time constraints.
std::vector<float> SoftmaxLayer::calcCEError(TENSOR(float) target) //uses labels, output and currentSize 
{
  std::vector<float> result = std::vector<float>(target.size(), 0.0f);
  for (int b = 0; b < target.size(); b++) {
  	for (int i = 0; i < output_forward.size(); i++) {
      //result[b] = fabs(target[b][0][0][i] - output_forward[b][0][0][i]);
      result[b] -= target[b][0][0][i] * log(output_forward[b][0][0][i]);
    }
  }
	return result;
}

TENSOR(float) SoftmaxLayer::backprob(TENSOR(float) feedback, float learningRate)
{
  output_backward = layerStrategy->backprob(feedback, output_forward);
	return output_backward;
}

TENSOR(float) SoftmaxLayer::backprob(TENSOR(float) updates)
{
  //output_backward = layerStrategy->backprob(feedback, output_forward);

    output_backward = updates;
    for (int b = 0; b < updates.size(); b++)
      for (int z = 0; z < updates[0].size(); z++)
          for (int y = 0; y < updates[0][0].size(); y++)
              for (int x = 0; x < updates[0][0][0].size(); x++)
                 output_backward[b][z][y][x] =  output_forward[b][z][y][x] - updates[b][z][y][x];
 
    std::cout << "Softmax output/expected: " << std::endl;
    for (int i = 0; i < output_forward[0][0][0].size(); i++){
      std::cout << i << " is: " <<output_forward[0][0][0][i] << " should be " << updates[0][0][0][i] << std::endl;
    }

  return output_backward;
}

void SoftmaxLayer::setMode(DeviceType device) {
    switch(device) {
    case DeviceType::CPP :
        layerStrategy = new SoftmaxLayerCPP();
        break;
    case DeviceType::ASIC :
        layerStrategy = new SoftmaxLayerASIC();
        break;
    case DeviceType::CPU :
        break;
    }
}
