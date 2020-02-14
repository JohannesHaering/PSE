#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class SoftmaxLayer : public ActivationLayer {

  public:
    SoftmaxLayer();
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net);
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback);
    float calcCEError(MatrixDefine::TENSOR(float) target);
};
#endif
