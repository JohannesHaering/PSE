#ifndef TRAINER_H_
#define TRAINER_H_

#include <opencv2/opencv.hpp>
#include "NeuralNetworkAdapter.hpp"
#include <vector>
#include <string>

class Trainer
{
public:
    Trainer(NeuralNetworkAdapter nn, float pres, std::vector<std::string> dirs);

};
#endif
