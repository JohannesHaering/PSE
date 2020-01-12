#include "InferencingDistributor.hpp"
#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "DispatchManager.hpp"
#include "ResultManager.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "Model.hpp"
#include <vector>

/*
* Finds the given result and calls the model to save it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributor::saveResult(int neuralNetworkId, int imageId) {
    Result result = resultManager.getSingleResult(neuralNetworkId, imageId);
    Model model = model.getInstance();
    model.saveResult(result);
}

/*
* Finds the given result and calls the view to display it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributor::drawResult(int nn_id, int input_id) {
    Result result = resultManager.getSingleResult(nn_id, input_id);
    drawResult(result);
}

/*
* Checks if all the needed information is given and the inferencer is ready to start
*/
bool InferencingDistributor::canStart() {
    return &neuralNetworks != NULL && neuralNetworks.size() != 0 && 
                &directories != NULL && directories.size() != 0 &&
                (view.showPageClassification || view.getSaveResultsClassification);
}

