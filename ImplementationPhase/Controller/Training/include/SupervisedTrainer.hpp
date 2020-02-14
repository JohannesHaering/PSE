#ifndef SUPERVISED_TRAINER_H_
#define SUPERVISED_TRAINER_H_

#include "TrainingMethods.hpp"
#include "NeuralNetwork.hpp"
#include "NetworkLayer.hpp"

#include <string>
#include <vector>
#include <list>
#include <opencv2/opencv.hpp>

class SupervisedTrainer : public TrainingMethods {
    public:
        NeuralNetworkAdapter* newEpoch() override;

    protected:
		virtual NeuralNetworkAdapter* backPropagate(cv::Mat image, std::vector<float> correctOutputVector, NeuralNetworkAdapter* network);
        //std::vector<float> gradientDescent(std::vector<float> weights, std::vector<float> correctOutputVector, std::vector<float> currentOutputVector);
        //std::vector<std::vector<float>> gradientDescent(std::vector<std::vector<float>> weights, std::vector<float> correctOutputVector, std::vector<float> currentOutputVector);
        //std::vector<std::vector<std::vector<float>>> gradientDescent(std::vector<std::vector<std::vector<float>>> weights, std::vector<float> correctOutputVector, std::vector<float> currentOutputVector);

    private:
        float learningRate = 0.1;
};
#endif