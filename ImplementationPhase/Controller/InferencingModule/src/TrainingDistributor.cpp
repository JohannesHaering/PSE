#include "Distributor.hpp"
#include "viewfacade.h"
#include "Trainer.hpp"
#include "TrainingDistributor.hpp"


TrainingDistributor::TrainingDistributor() {
	this->page = ViewFacade::getInstance()->getTraining();
}

/*
 * Starts the process and creates a trainer to deploy the data to.
 */
void TrainingDistributor::TrainingDistributor::startProcess() {
	float desprecision = page->getPrecision();
	Trainer trainer = Trainer(neuralNetwork, desprecision, directories);
}

/*
 * Checks if all needed data is given to start the process. 
 */
bool TrainingDistributor::canStart() {
	if (&neuralNetwork == NULL || &directories == NULL) {
		return false;
	}
	return true; 
}

/*
 * Enables or disables the start button of the view accordingly. 
 */ 
void TrainingDistributor::enableStart() {
	page->enableStart(canStart());
}
