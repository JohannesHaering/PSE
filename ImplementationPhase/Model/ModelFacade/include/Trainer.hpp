#ifndef TRAINER_H_
#define TRAINER_H_

#include "NeuralNetworkAdapter.hpp"
#include <string>;
#include <vector>

class Trainer
{
public:
    Trainer(NeuralNetworkAdapter na, float des, std::vector<std::string> dir);
};
#endif