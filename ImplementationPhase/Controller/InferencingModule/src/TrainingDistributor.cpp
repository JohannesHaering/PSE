#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "Trainer.hpp"
#include "TrainingDistributor.hpp"
#include "NeuralNetworkAdapter.hpp"


TrainingDistributor::TrainingDistributor() {
	this->page = ViewFacade::getInstance()->getTrainingPanel();
    this->neuralNetworks = std::vector<NeuralNetworkAdapter>();
    this->directories = std::vector<std::string>();
}

/*
 * Starts the process and creates a trainer to deploy the data to.
 */
void TrainingDistributor::TrainingDistributor::startProcess() {
	float desprecision = page->getPrecision();
    //TODO
    Trainer trainer = Trainer(neuralNetworks[0], desprecision, directories);
}

/*
 * Checks if all needed data is given to start the process. 
 */
bool TrainingDistributor::canStart() {
    if (neuralNetworks.size() == 0 || directories.size() == 0) {
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

ContentView* TrainingDistributor::getPage() {
    return this->page;
}
