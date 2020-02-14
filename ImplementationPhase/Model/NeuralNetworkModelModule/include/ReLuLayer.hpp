#ifndef RELU_H_
#define RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class ReLuLayer : public ActivationLayer {

  public:
    ReLuLayer();
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net) override;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) override;
};
#endif
