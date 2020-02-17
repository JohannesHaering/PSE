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

TENSOR(float) SoftmaxLayerCPP::forward(TENSOR(float) input_data)
{
    TENSOR(float) output = input_data;
    float sum = 0;
    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                    sum += exp(input_data[b][z][y][x]);
        

    for (int b = 0; b < input_data.size(); b++)
        for (int z = 0; z < input_data[0].size(); z++)
            for (int y = 0; y < input_data[0][0].size(); y++)
                for (int x = 0; x < input_data[0][0][0].size(); x++)
                    output[b][z][y][x] = exp(input_data[b][z][y][x]) / sum ;
    return output;
}

TENSOR(float) SoftmaxLayerCPP::backprob(TENSOR(float) updates, TENSOR(float) output_forward)
{
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
