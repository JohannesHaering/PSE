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
    TENSOR(float) forward(TENSOR(float) net);
    TENSOR(float) backprob(TENSOR(float) feedback);
};
#endif
