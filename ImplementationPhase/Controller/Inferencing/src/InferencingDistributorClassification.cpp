#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"


InferencingDistributorClassification::InferencingDistributorClassification(){
    this->view = ViewFacade::getInstance();
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorClassification::enableStart(){
    view.startButtonEnableClassification(canStart());
}

/*
* Starts the classification process. 
* Gets information from the view and dispatches the images accordingly.
*/
void InferencingDistributorClassification::startProcess(){
    dispatcher.setNeuralNetworkList(neuralNetworks);
    //TODO: correct mode
    std::vector<std::string> platforms = view.getPlatformsClassification();
    std::string operatingMode = view.getOperatingModeClassification();
    Mode mode = {};
    dispatcher.setMode(mode);
    resultManager = dispatcher.dispatchImages(directories);
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(Result result) {
    view.setResultClassification(result);
}    
    