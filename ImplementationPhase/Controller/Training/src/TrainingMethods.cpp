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
/*
std::vector<float> TrainingMethods::excecuteNeuralNetwork(NeuralNetwork toExcecute, cv::Mat image)
{
    std::list<NeuralNetwork> neuralNetworkList;
    std::list<cv::Mat> imageList;
    neuralNetworkList.push_back(toExcecute);
    imageList.push_back(image);

    Channel usedChannel = CPUChannel(DEVICE_ID, neuralNetworkList);
    auto result = usedChannel.sendImageList(imageList);
    
    // get cached layer output

    return supplyer->createOutputVector(result);
}
*/
cv::Mat TrainingMethods::loadImage(std::string id)
{
    return supplyer->getImage(id);
}

std::vector<float> TrainingMethods::loadCorrectOutputVector(std::string id)
{
    return supplyer->getOutputVector(id);
}