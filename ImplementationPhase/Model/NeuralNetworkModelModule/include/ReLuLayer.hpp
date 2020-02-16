#ifndef RELU_H_
#define RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "ReLuLayerStrategy.hpp"

class ReLuLayer : public ActivationLayer {
  private:
    ReLuLayerStrategy* layerStrategy;
  public:
    ReLuLayer();
    TENSOR(float) forward(TENSOR(float) net);
	  TENSOR(float) backprob(TENSOR(float) feedback);
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
