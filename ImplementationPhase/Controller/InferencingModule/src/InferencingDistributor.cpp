#include "InferencingDistributor.hpp"
#include "Distributor.hpp"
#include "ViewFacade.hpp"
#include "DispatchManager.hpp"
#include "ResultManager.hpp"
#include "NeuralNetworkAdapter.hpp"
#include "ResultFacade.hpp"
#include <vector>
#include <string>


/*
* Checks if all the needed information is given and the inferencer is ready to start
*/
bool InferencingDistributor::canStart() {
    return &neuralNetworks != NULL && neuralNetworks.size() != 0 && 
                &directories != NULL && directories.size() != 0 &&
                (page->getShowResults() || page->getSaveResults());
}

