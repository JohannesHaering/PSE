#include "ReLuLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

ReLuLayerCPP::ReLuLayerCPP(){

}

TENSOR(float) ReLuLayerCPP::forward(TENSOR net)
{
    TENSOR(float) output = net;
    for (int b = 0; b < net.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 output[b][z][y][x] = net[b][z][y][x] > 0 ? net[b][z][y][x] : 0;
    return output;
}

TENSOR(float) ReLuLayerCPP::backprob(TENSOR(float) feedback)
{
    TENSOR(float) output = feedback;
    for (int b = 0; b < feedback.size(); b++)
        for (int z = 0; z < feedback[0].size(); z++)
            for (int y = 0; y < feedback[0][0].size(); y++)
                for (int x = 0; x < feedback[0][0][0].size(); x++)
                    output_backward[b][z][y][x] = feedback[b][z][y][x] > 0 ? feedback[b][z][y][x] : 0;
    return output;
}
