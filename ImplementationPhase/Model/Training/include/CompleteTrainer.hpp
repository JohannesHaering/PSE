#ifndef COMPLETE_TRAINER_H_
#define COMPLETE_TRAINER_H_

#include <vector>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"

class CompleteTrainer
{
public:
	CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate);
	std::vector<float> forward(std::vector<float> input);
	void train(std::vector<float> target);
  float calcCEError(std::vector<float> target);

private:
	std::vector<float> output;
	std::vector<float> feedback;

	float learningRate;
	NeuralNetworkAdapter* neuralNetwork;
};
#endif
