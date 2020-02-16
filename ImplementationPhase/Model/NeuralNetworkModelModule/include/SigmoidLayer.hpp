#ifndef SIGMOID_LAYER_H_
#define SIGMOID_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SigmoidLayerStrategy.hpp"

class SigmoidLayer : public ActivationLayer {

  SigmoidLayerStrategy* layerStrategy;

  public:
    SigmoidLayer();
    std::vector<float> forward(std::vector<float> net);
    std::vector<float> backprob(std::vector<float> feedback);
};
#endif
