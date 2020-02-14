#ifndef TRANSFER_TRAINER_H_
#define TRANSFER_TRAINER_H_

#include "NeuralNetwork.hpp"
#include "NetworkLayer.hpp"
#include "SupervisedTrainer.hpp"

#include <opencv2/opencv.hpp>
#include <vector>

class TransferTrainer : public SupervisedTrainer {
    public:
        NeuralNetwork backPropagate(std::vector<float> correctOutputVector, std::vector<float> currentOutputVector, NeuralNetwork network) override;
};
#endif