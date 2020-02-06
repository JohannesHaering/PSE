#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "CompleteTrainer.hpp"
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 

class Trainer
{
public:
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData);
	void startTraining();
private:
	//void train(std::vector<float> target);
	void loadDataset();
    float testAcc();
	void saveNewNeuralNetwork();
	float getNewTrainingsAccuracy();
	float getNewTestAccuracy();

	float desiredPrecision;
	NeuralNetworkAdapter* neuralNetwork;
	std::string trainData;
	float testAccVal;
	float trainingsAcc;
    CompleteTrainer trainer;
    
    std::vector<std::vector<float>> dataset_train_images;
    std::vector<std::vector<float>> dataset_test_images;
    std::vector<float> dataset_train_labels;
    std::vector<float> dataset_test_labels;
};
#endif
