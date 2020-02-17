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
      for (int z = 0; z < input_data[0].size(); z++)
          for (int y = 0; y < input_data[0][0].size(); y++)
              for (int x = 0; x < input_data[0][0][0].size(); x++)
                 output_forward[b][z][y][x] = input_data[b][z][y][x] > 0 ? input_data[b][z][y][x] : 0.01 * input_data[b][z][y][x];
    return output_forward;
}

TENSOR(float) LeakyReLuLayerCPP::backprob(TENSOR(float) updates)
{
    TENSOR(float) output_backward = updates;
    for (int b = 0; b < updates.size(); b++)
        for (int z = 0; z < updates[0].size(); z++)
            for (int y = 0; y < updates[0][0].size(); y++)
                for (int x = 0; x < updates[0][0][0].size(); x++)
                    output_backward[b][z][y][x] = updates[b][z][y][x] > 0 ? updates[b][z][y][x] : 0.01 * updates[b][z][y][x];
    return output_backward;
}
