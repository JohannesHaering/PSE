#ifndef TRAINING_METHODS_H_
#define TRAINING_METHODS_H_

#include "NeuralNetworkFacade.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "TrainerDataSupply.hpp"

#include <string>
#include <list>
#include <map>
#include <vector>
#include <opencv2/opencv.hpp>

class TrainingMethods
{
public:
	TrainingMethods(TrainerDataSupply* supplyer);
	virtual NeuralNetworkAdapter* newEpoch();
    float getTestAccuracy();
    float getTrainingsAccuracy();

protected:
    // std::vector<float> excecuteNeuralNetwork(NeuralNetwork toExcecute, cv::Mat image);
    cv::Mat loadImage(std::string id);
	std::vector<float> loadCorrectOutputVector(std::string id);
	NeuralNetworkAdapter* neuralNetwork;
    TrainerDataSupply* supplyer;
    int correctTrainingGuesses;
    int correctTestGuesses;
    int size;

    const int DEVICE_ID = 0;
};
#endif