#ifndef NEURAL_NETWORK_FACADE_H_
#define NEURAL_NETWORK_FACADE_H_

#include "NeuralNetwork.hpp"
#include "ModelFacade.hpp"

#include <string>

class NeuralNetworkFacade : public ModelFacade
{
public:
    NeuralNetwork loadNeuralNetwork(std::string path);
    bool saveNeuralNetwork(NeuralNetwork neuralNetwork, std::string path);
};
#endif