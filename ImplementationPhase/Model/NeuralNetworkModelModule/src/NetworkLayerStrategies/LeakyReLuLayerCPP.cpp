#include "LeakyReLuLayerCPP.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

LeakyReLuLayerCPP::LeakyReLuLayerCPP(){

}

TENSOR(float) LeakyReLuLayerCPP::forward(TENSOR(float) net)
{
    TENSOR(float) output_forward = net;
    for (int b = 0; b < net.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 output_forward[b][z][y][x] = net[b][z][y][x] > 0 ? net[b][z][y][x] : 0.01 * net[b][z][y][x];
    return output_forward;
}

TENSOR(float) LeakyReLuLayerCPP::backprob(TENSOR(float) feedback)
{
    TENSOR(float) output_backward = feedback;
    for (int b = 0; b < feedback.size(); b++)
        for (int z = 0; z < feedback[0].size(); z++)
            for (int y = 0; y < feedback[0][0].size(); y++)
                for (int x = 0; x < feedback[0][0][0].size(); x++)
                    output_backward[b][z][y][x] = feedback[b][z][y][x] > 0 ? feedback[b][z][y][x] : 0.01 * feedback[b][z][y][x];
    return output_backward;
}
