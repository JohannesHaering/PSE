#include "SoftmaxLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

SoftmaxLayerCPP::SoftmaxLayerCPP(){

}

MatrixDefine::TENSOR(float) SoftmaxLayerCPP::forward(MatrixDefine::TENSOR net)
{
    MatrixDefine::TENSOR(float) output = net;
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
                    output[b][z][y][x] = exp(net[b][z][y][x]) / sum ;
    return output;
}

MatrixDefine::TENSOR(float) SoftmaxLayerCPP::backprob(MatrixDefine::TENSOR(float) feedback, MatrixDefine::TENSOR(float) output_forward)
{
    MatrixDefine::TENSOR(float) output = feedback;
    for (int b = 0; b < feedback.size(); b++)
      for (int z = 0; z < feedback[0].size(); z++)
          for (int y = 0; y < feedback[0][0].size(); y++)
              for (int x = 0; x < feedback[0][0][0].size(); x++)
                 output[b][z][y][x] =  output_forward[b][z][y][x] - feedback[b][z][y][x];
    return output;
}
