#ifndef TRAINING_DISTRIBUTOR_H_
#define TRAINING_DISTRIBUTOR_H_

#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "Trainer.hpp"

class TrainingDistributor : public Distributor {

	public:
		TrainingDistributor();
		void startProcess();
		bool canStart();
		void enableStart();

	private:
		NeuralNetworkAdapter neuralNetwork;
		ViewFacade view;
		std::vector<std::string> directories; 	

};
#endif