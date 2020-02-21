#include "SoftmaxLayerCPP.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

SoftmaxLayerCPP::SoftmaxLayerCPP(){

}

void SoftmaxLayerCPP::calcMaxVec(std::vector<float> *maxVec, TENSOR(float) net)
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

TENSOR(float) SoftmaxLayerCPP::forward(TENSOR(float) input_data)
{
    std::cout << "SoftmaxStrategieCPPCPU forward" << std::endl;
    TENSOR(float) output = input_data;
    std::vector<float> sum = std::vector<float>(input_data.size(), 0.0f);
    std::vector<float> max = std::vector<float>(input_data.size());
    calcMaxVec(&max, input_data);
    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                    sum[b] += exp(input_data[b][z][y][x] - max[b]);
    std::cout << "sum: 0 " << sum[0] << std::endl;   

    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                    output[b][z][y][x] = exp(input_data[b][z][y][x] - max[b]) / sum[b] ;
    for (int i = 0; i < output[0][0][0].size(); i++){
      std::cout << output[0][0][0][i] << " " << std::endl;
    }
    return output;
}

TENSOR(float) SoftmaxLayerCPP::backprob(TENSOR(float) updates, TENSOR(float) output_forward)
{
    std::cout << "softmaxStrategieCPPCPU backward" << std::endl;
    std::cout << "printing updates" << std::endl;
    for (int i = 0; i < updates[0][0][0].size(); i++){
      if (updates[0][0][0][i] == 1) std::cout << " should be : " << i << std::endl;
    }
    std::cout << "printing output_forward" << std::endl;
    for (int i = 0; i < output_forward[0][0][0].size(); i++){
      std::cout << output_forward[0][0][0][i] << " ";
    }
    
    std::cout << std::endl << "Softmax backward" << std::endl;
    TENSOR(float) output = updates;
    for (int b = 0; b < updates.size(); b++)
      for (int z = 0; z < updates[0].size(); z++)
          for (int y = 0; y < updates[0][0].size(); y++)
              for (int x = 0; x < updates[0][0][0].size(); x++)
                 output[b][z][y][x] =  output_forward[b][z][y][x] - updates[b][z][y][x];
    return output;
}

TENSOR(float) SoftmaxLayerCPP::backprob(TENSOR(float) updates){

}
