#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"

/*
* Creates a InferencingDistributor for Classification.
* Parameters:
* -Inference page: the corresponding page
*/
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
    std::vector<Device> platforms = page.getPlatforms();
    std::string operatingMode = page.getOperatingMode();
	Mode mode = Mode();
	mode.setModeName(operatingMode);
	mode.setAllowedDeviceList(platforms);
	mode.setImageList(directories);
	mode.setNeuralNetworkList(neuralNetworks);
    dispatcher.setMode(mode);
    resultManager = dispatcher.dispatchImages(directories);
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(Result result) {
    page.setResult(result);
}    
    