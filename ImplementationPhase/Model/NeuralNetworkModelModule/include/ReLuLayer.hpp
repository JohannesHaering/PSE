#ifndef RELU_H_
#define RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class ReLuLayer : public ActivationLayer {
  private:
    ReLuLayerStrategy layerStrategy;
  public:
    ReLuLayer();
    std::vector<float> forward(std::vector<float> net);
	  std::vector<float> backprob(std::vector<float> feedback);
};
#endif
