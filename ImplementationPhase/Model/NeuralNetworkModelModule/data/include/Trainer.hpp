#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include "Layer.hpp"
//Instanz, initiated with vector<Layer>. 
//has a .train(std::vector<float> input, std::vector<int> target) function and a .infer(std::vector<float> input) function. 

class Trainer
{
	public: 
		Trainer(std::vector<Layer*> LayerVec, float learningRate);
		void Train(std::vector<float> target);
		std::vector<float> Infer(std::vector<float> input);
	private:
		float learningRate;
		std::vector<Layer*> LayerVec;
};
#endif
