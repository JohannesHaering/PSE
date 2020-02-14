#ifndef SIGMOID_LAYER_H_
#define SIGMOID_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class SigmoidLayer : public ActivationLayer {

  public:
    SigmoidLayer();
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net) override;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) override;
};
#endif
