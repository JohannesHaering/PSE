#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include <string>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "CompleteTrainer.hpp"

class Trainer
{
public:
	Trainer(NeuralNetworkAdapter* neuralNetwork, float desiredPrecision, std::string trainData);
	void startTraining();
private:
	void loadDataset();
	void saveNewNeuralNetwork();
	float getNewTrainingsAccuracy();
	float getNewTestAccuracy();

  static int batchSize = 16;
	float desiredPrecision;
  std::vector<float> testAcc;
  std::vector<float> trainingAcc;
	NeuralNetworkAdapter* neuralNetwork;
	std::string trainData;
  CompleteTrainer trainer;
    
  std::vector<std::vector<float>> dataset_train_images;
  std::vector<std::vector<float>> dataset_test_images;
  std::vector<std::vector<float>> dataset_train_labels;
  std::vector<std::vector<float>> dataset_test_labels;
};
#endif
