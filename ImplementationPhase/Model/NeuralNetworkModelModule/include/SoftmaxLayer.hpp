#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SoftmaxLayerStrategy.hpp"

class SoftmaxLayer : public ActivationLayer {

private:
	SoftmaxLayerStrategy* layerStrategy;

public:
    SoftmaxLayer();
    TENSOR(float) forward(TENSOR(float) net);
	  TENSOR(float) backprob(TENSOR(float) feedback);
    std::vector<float> calcCEError(TENSOR(float) target);
    void setMode(DeviceType device, cl_int deviceID);
};
#endif
