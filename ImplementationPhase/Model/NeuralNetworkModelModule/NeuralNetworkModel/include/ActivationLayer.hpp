#ifndef ACTIVATIONLAYER_H_
#define ACTIVATIONLAYER_H_

#include <string>
#include <vector>
#include "NetworkLayer.hpp"
#include "Activation.hpp"

class ActivationLayer : public NetworkLayer {
public:
	virtual std::vector<float> backprob(std::vector<float> feedback) = 0;
	std::vector<float> backprob(std::vector<float> feedback, float learningrate) override;
	Activation getActivationType();
protected:
	Activation activationType;
};
#endif
