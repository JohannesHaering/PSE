#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"


InferencingDistributorClassification::InferencingDistributorClassification(InferencePage page)
{
	this->page = page;
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorClassification::enableStart(){
    page.startButtonEnable(canStart());
}

/*
* Starts the classification process. 
* Gets information from the view and dispatches the images accordingly.
*/
void InferencingDistributorClassification::startProcess(){
    dispatcher.setNeuralNetworkList(neuralNetworks);
    //TODO: correct mode
    std::vector<std::string> platforms = page.getPlatforms();
    std::string operatingMode = page.getOperatingMode();
    Mode mode = {};
    dispatcher.setMode(mode);
    resultManager = dispatcher.dispatchImages(directories);
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(Result result) {
    page.setResult(result);
}    
    