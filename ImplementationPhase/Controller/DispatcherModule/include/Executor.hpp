#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"

class Executor
{
public:
	Executor(NeuralNetworkAdapter* neuralNetwork);
  std::vector<float> execute(TENSOR(float) input);
private:
	NeuralNetworkAdapter* neuralNetwork;
};
#endif
