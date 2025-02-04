#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "CompleteTrainer.hpp"
#include "TrainerDataSupply.hpp"

class Trainer
{
public:
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, float learningrate);
	void startTraining();
	static const int batchSize = 16;

private:
	void saveNewNeuralNetwork();
	float getNewTrainingsAccuracy();
	float getNewTestAccuracy();
	void loadDataset();

  std::string trainData;
	float desiredPrecision;
	std::vector<float> testAcc;
	std::vector<float> trainAcc;
	NeuralNetworkAdapter* neuralNetwork;
	CompleteTrainer trainer;
	TrainerDataSupply* supplyer;
};
#endif
