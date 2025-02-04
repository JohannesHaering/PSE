#ifndef NEURAL_NETWORK_SETTER_H_
#define NEURAL_NETWORK_SETTER_H_

#include "Inferencer.hpp"
#include "NeuralNetworkAdapter.hpp"
#include <vector>

class NeuralNetworkSetter {

    public: 
        NeuralNetworkSetter(Inferencer *inferencer);
        void setNeuralNetwork(std::vector<std::string> directories);
		Inferencer* getInferencer();

    private:
        Inferencer *inferencer;    

};
#endif