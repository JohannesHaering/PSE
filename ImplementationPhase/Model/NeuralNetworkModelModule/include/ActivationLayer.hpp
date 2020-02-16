#ifndef ACTIVATIONLAYER_H_
#define ACTIVATIONLAYER_H_

#include <string>
#include <vector>
#include "NetworkLayer.hpp"

class ActivationLayer : public NetworkLayer {

  public:
	  virtual TENSOR(float) backprob(TENSOR(float) feedback) = 0;
	  TENSOR(float) backprob(TENSOR(float) feedback, float learningrate) override;
};
#endif
