#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 

class Trainer
{
public:
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData);
	void startTraining();
	void train(std::vector<float> target);
private:
	void loadDataset();
	float desiredPrecision;
	NeuralNetworkAdapter* neuralNetwork;
	std::string trainData;
	float testAcc;
	float trainingsAcc;
	void saveNewNeuralNetwork();
	float getNewTrainingsAccuracy();
	float getNewTestAccuracy();
};
#endif
