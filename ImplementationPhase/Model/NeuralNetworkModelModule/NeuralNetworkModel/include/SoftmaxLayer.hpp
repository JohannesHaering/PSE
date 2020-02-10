#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class SoftmaxLayer : public ActivationLayer {

  public:
    std::vector<float> forward(std::vector<float> net);
	  std::vector<float> backprob(std::vector<float> target);
    float calcCEError();
  private: 
    float error;
    std::vector<float> target;  
};
#endif
