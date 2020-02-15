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
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData);
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData, int batchSize);
	void startTraining();
private:
	void saveNewNeuralNetwork();
	float getNewTrainingsAccuracy();
	float getNewTestAccuracy();

	int batchSize = 16;
	float desiredPrecision;
	std::vector<float> testAcc;
	std::vector<float> trainingAcc;
	NeuralNetworkAdapter* neuralNetwork;
	CompleteTrainer trainer;
	TrainerDataSupply* supplyer;
};
#endif
