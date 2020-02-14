#include "ReLuLayer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init
ReLuLayer::ReLuLayer()
{
  layerType = LayerType::RELU;
}


MatrixDefine::TENSOR(float) ReLuLayer::forward(MatrixDefine::TENSOR(float) net)
{
  this->net = net;
  this->output_forward = net;
  for (int b = 0; b < net.size(); b++)
      for (int z = 0; z < net[0].size(); z++)
          for (int y = 0; y < net[0][0].size(); y++)
              for (int x = 0; x < net[0][0][0].size(); x++)
                 output_forward[b][z][y][x] = net[b][z][y][x] > 0 ? net[b][z][y][x] : 0;
	return output_forward;
}


MatrixDefine::TENSOR(float) ReLuLayer::backprob(MatrixDefine::TENSOR(float) feedback)
{
  output_backward = feedback;
  
  for (int b = 0; b < feedback.size(); b++)
      for (int z = 0; z < feedback[0].size(); z++)
          for (int y = 0; y < feedback[0][0].size(); y++)
              for (int x = 0; x < feedback[0][0][0].size(); x++)
                 output_backward[b][z][y][x] = feedback[b][z][y][x] > 0 ? feedback[b][z][y][x] : 0;

	return output_backward;
}
