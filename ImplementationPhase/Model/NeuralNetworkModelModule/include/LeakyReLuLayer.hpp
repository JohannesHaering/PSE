#ifndef LEAKY_RELU_H_
#define LEAKY_RELU_H_

#include <string>
#include <vector>
#include "ActivationLayer.hpp"
#include "LeakyReLuLayerStrategy.hpp"

class LeakyReLuLayer : public ActivationLayer {

private:
	LeakyReLuLayerStrategy* layerStrategy;
public:
	LeakyReLuLayer();
	std::vector<float> forward(std::vector<float> net);
	std::vector<float> backprob(std::vector<float> feedback);
};
#endif
