#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SoftmaxLayer.hpp"

class SoftmaxLayer : public ActivationLayer {

private:
	SoftmaxStrategy* layerStrategy;

public:
    SoftmaxLayer();
    TENSOR(float) forward(TENSOR(float) net);
	  TENSOR(float) backprob(TENSOR(float) feedback);
    float calcCEError(TENSOR(float) target);
    void setMode(DeviceType device, cl_int deviceID);
};
#endif
