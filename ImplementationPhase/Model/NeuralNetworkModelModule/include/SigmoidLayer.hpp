#ifndef SIGMOID_LAYER_H_
#define SIGMOID_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SigmoidLayerStrategy.hpp"
#include "MatrixDefine.hpp"

class SigmoidLayer : public ActivationLayer {

  SigmoidLayerStrategy* layerStrategy;

  public:
    SigmoidLayer();
    TENSOR(float) forward(TENSOR(float) net) override;
	  TENSOR(float) backprob(TENSOR(float) feedback) override;
    TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) override;
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
