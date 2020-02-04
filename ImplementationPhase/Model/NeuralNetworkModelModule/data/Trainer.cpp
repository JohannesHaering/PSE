#include "Trainer.hpp"
#include "Layer.hpp"
#include <vector>
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 


Trainer::Trainer(std::vector<Layer*> LayerVec, float learningRate) : LayerVec(LayerVec), learningRate(learningRate) {}


void Trainer::Train(std::vector<float> target)
{
	std::vector<float> output; 
	std::vector<float> tmp = target;

	for (auto& Layer : LayerVec)
	{
		output = Layer->bprop(target, learningRate);
		tmp = output;
	}
	learningRate *= 0.99;
}


std::vector<float> Trainer::Infer(std::vector<float> input)
{
	std::vector<float> tmp = input;
	std::vector<float> output;
	for (auto& Layer : LayerVec)
	{
		output = Layer->fprop(tmp);
		tmp = output;
	}
	return output;
}

