#include "InferencingDistributor.hpp"
#include "Distributor.hpp"
#include "viewfacade.h"
#include "DispatchManager.hpp"
#include "ResultManager.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "ResultFacade.hpp"
#include <vector>
#include <string>

InferencingDistributor::InferencingDistributor() : dispatcher(DispatchManager::getInstance()), resultManager(ResultManager())
{
}

/*
* Finds the given result and calls the model to save it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributor::saveResult(std::string neuralNetworkId, std::string imageId, std::string path)
{
    Result* result = (Result*)resultManager.getSingleResult(neuralNetworkId, imageId);
	ParseResultFacade model = ParseResultFacade();
    model.writeClassificationResult(*result, path);
}

/*
* Finds the given result and calls the view to display it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributor::drawResult(std::string nn_id, std::string input_id) {
    Result* result = (Result*)resultManager.getSingleResult(nn_id, input_id);
    page.setResult(*result);
}

/*
* Checks if all the needed information is given and the inferencer is ready to start
*/
bool InferencingDistributor::canStart() {
    return &neuralNetworks != NULL && neuralNetworks.size() != 0 && 
                &directories != NULL && directories.size() != 0 &&
                (page.getShowResults() || page.getSaveResults());
}

