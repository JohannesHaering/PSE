#include "Layer.hpp"
#include <vector>

//ActivationFunctions work on net[j], so a size does not need to be set on init

virtual std::vector<float> Layer::fprop(std::vector<float> net) = 0;
virtual std::vector<float> Layer::bprop(std::Vector<float> feedback) = 0;

