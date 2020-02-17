#include "LeakyReLuLayerCPP.hpp"
#include "MatrixDefine.hpp"
#include <vector>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

LeakyReLuLayerCPP::LeakyReLuLayerCPP(){

}

TENSOR(float) LeakyReLuLayerCPP::forward(TENSOR(float) input_data)
{
	TENSOR(float) output_forward =  input_data;
    for (int b = 0; b < input_data.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 output_forward[b][z][y][x] = net[b][z][y][x] > 0 ? net[b][z][y][x] : 0.01 * net[b][z][y][x];
    return output_forward;
}

TENSOR(float) LeakyReLuLayerCPP::backprob(TENSOR(float) updates)
{
    TENSOR(float) output_backward = updates;
    for (int b = 0; b < updates.size(); b++)
        for (int z = 0; z < updates[0].size(); z++)
            for (int y = 0; y < updates[0][0].size(); y++)
                for (int x = 0; x < updates[0][0][0].size(); x++)
                    output_backward[b][z][y][x] = updates[b][z][y][x] > 0 ? udaptes[b][z][y][x] : 0.01 * updates[b][z][y][x];
    return output_backward;
}
