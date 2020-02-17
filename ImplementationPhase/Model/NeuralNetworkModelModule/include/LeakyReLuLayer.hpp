#ifndef LEAKY_RELU_H_
#define LEAKY_RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "LeakyReLuLayerStrategy.hpp"

class LeakyReLuLayer : public ActivationLayer {

  private: 
    LeakyReLuLayerStrategy* layerStrategy;
  public:
    LeakyReLuLayer();
    TENSOR(float) forward(TENSOR(float) net);
	  TENSOR(float) backprob(TENSOR(float) feedback);
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
