#ifndef RELU_H_
#define RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "ReLuLayerStrategy.hpp"

class ReLuLayer : public ActivationLayer {

  public:
    ReLuLayer();
    ReLuLayerStrategy layerStrategy;
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net) override;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) override;
    void setMode(DeviceType device, cl_int deviceID) override;
};
#endif
