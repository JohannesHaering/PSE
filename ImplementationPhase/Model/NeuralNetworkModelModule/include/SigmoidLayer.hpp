#ifndef SIGMOID_LAYER_H_
#define SIGMOID_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "SigmoidLayerStrategy.hpp"

class SigmoidLayer : public ActivationLayer {
  private:
    SigmoidLayerStrategy layerStrategy;

  public:
    SigmoidLayer();
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net) override;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) override;
    void setMode(DeviceType device, cl_int deviceID);
};
#endif
