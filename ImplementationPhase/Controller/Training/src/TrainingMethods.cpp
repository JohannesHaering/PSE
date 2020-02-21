#include "TrainingMethods.hpp"
#include "TrainerDataSupply.hpp"
#include "CPUChannel.hpp"
#include "Channel.hpp"

#include <vector>
#include <opencv2/opencv.hpp>

TrainingMethods::TrainingMethods(TrainerDataSupply* supplyer) {
	this->supplyer = supplyer;
}

float TrainingMethods::getTestAccuracy()
{
    return ((float)correctTrainingGuesses) / ((float)size);
}

float TrainingMethods::getTrainingsAccuracy()
{
    return ((float)correctTestGuesses) / ((float)size);
}

cv::Mat TrainingMethods::loadImage(std::string id)
{
    return supplyer->getImage(id);
}

std::vector<float> TrainingMethods::loadCorrectOutputVector(std::string id)
{
    return supplyer->getOutputVector(id);
}