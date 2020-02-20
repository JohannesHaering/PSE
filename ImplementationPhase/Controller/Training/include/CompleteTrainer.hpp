#ifndef COMPLETE_TRAINER_H_
#define COMPLETE_TRAINER_H_

#include <vector>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "MatrixDefine.hpp"

class CompleteTrainer
{
public:
	CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate);
	TENSOR(float) forward(TENSOR(float) input);
	void train(TENSOR(float) target);
	TENSOR(float) calcCEError(TENSOR(float) target);

private:
  long processedBatches;
	TENSOR(float) output;
	TENSOR(float) feedback;

	int batchSize;
	float learningRate;
	NeuralNetworkAdapter* neuralNetwork;
};
#endif
