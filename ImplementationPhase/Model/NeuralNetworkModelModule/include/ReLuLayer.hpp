#ifndef RELU_H_
#define RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "ReLuLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class ReLuLayer : public ActivationLayer {
  private:
    ReLuLayerStrategy* layerStrategy;
  public:
    ReLuLayer();
    TENSOR(float) forward(TENSOR(float) net) override;
	  TENSOR(float) backprob(TENSOR(float) feedback) override;
	  TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) override;
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
