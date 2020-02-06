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
    std::cout << "lebe noch1" << std::endl;
	float desprecision = page->getPrecision();
    //TODO
    std::cout << "lebe noch1.5" << std::endl;
    Trainer trainer = Trainer(&(neuralNetworks[0]), desprecision, directories[0]);
    std::cout << "lebe noch2" << std::endl;
	trainer.startTraining();
    std::cout << "lebe immer noch3" << std::endl;
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

TrainingPanel* TrainingDistributor::getPage() {
    return this->page;
}
