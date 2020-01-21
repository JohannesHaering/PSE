#ifndef NEURAL_NETWORK_FACADE_H_
#define NEURAL_NETWORK_FACADE_H_

#include "NeuralNetwork.hpp"
#include "ModelFacade.hpp"

#include <string>
#include <list>

class NeuralNetworkFacade : public ModelFacade
{
public:
    NeuralNetwork loadNeuralNetwork(std::string path);
    std::list<NeuralNetwork> loadNeuralNetworks(std::list<std::string> paths);
    bool saveNeuralNetwork(NeuralNetwork neuralNetwork, std::string path);
    bool saveNeuralNetworks(std::list<NeuralNetwork> neuralNetworks, std::list<std::string> paths);
};
#endif