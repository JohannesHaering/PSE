#ifndef SIGMOID_LAYER_H_
#define SIGMOID_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class SigmoidLayer : public ActivationLayer {

  public:
    std::vector<float> forward(std::vector<float> net);
    std::vector<float> backprob(std::vector<float> feedback);
};
#endif
