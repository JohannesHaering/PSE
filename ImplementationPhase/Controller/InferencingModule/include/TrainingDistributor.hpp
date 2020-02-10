#ifndef TRAINING_DISTRIBUTOR_H_
#define TRAINING_DISTRIBUTOR_H_

#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "Trainer.hpp"
#include "NeuralNetworkAdapter.hpp"

class TrainingDistributor : public Distributor {

	public:
		TrainingDistributor();
		void startProcess();
		bool canStart();
		void enableStart();
		TrainingPanel* getPage() override;

	private:	
		TrainingPanel* page;

};
#endif
