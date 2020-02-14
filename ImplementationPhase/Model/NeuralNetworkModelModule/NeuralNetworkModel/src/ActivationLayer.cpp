#include "ActivationLayer.hpp"
#include "Activation.hpp"

std::vector<float> ActivationLayer::backprob(std::vector<float> feedback, float learningrate) {
	return this->backprob(feedback);
}

Activation ActivationLayer::getActivationType() { return activationType; }
