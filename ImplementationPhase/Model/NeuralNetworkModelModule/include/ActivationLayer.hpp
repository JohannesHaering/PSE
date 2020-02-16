#ifndef ACTIVATIONLAYER_H_
#define ACTIVATIONLAYER_H_

#include <string>
#include <vector>
#include "NetworkLayer.hpp"

class ActivationLayer : public NetworkLayer {

  public:
	  virtual MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback) = 0;
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback, float learningrate) override;
};
#endif
