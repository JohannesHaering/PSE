#ifndef LEAKY_RELU_H_
#define LEAKY_RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "LeakyReLuLayerStrategy.hpp"

class LeakyReLuLayer : public ActivationLayer {

  public:
    LeakyReLuLayer();
    LeakyReLuLayerStrategy layerStrategy;
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net) override;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) override;
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
