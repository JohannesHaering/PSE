#ifndef COMPLETE_TRAINER_H_
#define COMPLETE_TRAINER_H_

#include <vector>
#include "NetworkLayer.hpp"
#include "NeuralNetworkAdapter.hpp"
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 

class CompleteTrainer
{
public:
	CompleteTrainer(NeuralNetworkAdapter* neuralNetwork, float learningRate);
	std::vector<float> forward(std::vector<float> input);
	void train(std::vector<float> target);
private:
	float learningRate;
	NeuralNetworkAdapter* neuralNetwork;
};
#endif
