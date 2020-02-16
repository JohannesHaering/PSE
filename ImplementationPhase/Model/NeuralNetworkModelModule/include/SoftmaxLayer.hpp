#ifndef SOFTMAX_LAYER_H_
#define SOFTMAX_LAYER_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"

class SoftmaxLayer : public ActivationLayer {

<<<<<<< HEAD
public:
	SoftmaxLayer();
	std::vector<float> forward(std::vector<float> net);
	std::vector<float> backprob(std::vector<float> target);
	float calcCEError(std::vector<float> tartget);
	float calcCEError();
private:
	float error;
	std::vector<float> target;
=======
  public:
    SoftmaxLayer();
    MatrixDefine::TENSOR(float) forward(MatrixDefine::TENSOR(float) net);
	  MatrixDefine::TENSOR(float) backprob(MatrixDefine::TENSOR(float) feedback);
    float calcCEError(MatrixDefine::TENSOR(float) target);
    void setMode(DeviceType device, cl_int deviceID);
}
>>>>>>> 37e46e75251dfb09932a192833da4d75c3659b28
};
#endif
