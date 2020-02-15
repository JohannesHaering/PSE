#ifndef COMPLETE_TRAINER_H_
#define COMPLETE_TRAINER_H_

#include <vector>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"

class CompleteTrainer
{
public:
	CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate, int batchSize);
	TENSOR(float) forward(TENSOR(float) input);
	void train(TENSOR(float) target);
	float calcCEError(TENSOR(float) target);

private:
	TENSOR(float) output;
	TENSOR(float) feedback;

	int batchSize;
	float learningRate;
	NeuralNetworkAdapter* neuralNetwork;
};
#endif
