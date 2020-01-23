#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"

/*
* Creates a InferencingDistributor for Classification.
* Parameters:
* -Inference page: the corresponding page
*/
InferencingDistributorClassification::InferencingDistributorClassification(InferencePageAdapter page)
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
void InferencingDistributorClassification::startProcess()
{
	std::list<NeuralNetworkAdapter> nnlist(neuralNetworks.begin(), neuralNetworks.end());
    dispatcher.setNeuralNetworkList(nnlist);
    std::vector<Device> platforms = page.getDevices();
    std::string operatingMode = page.getOperatingMode();
	Mode mode = Mode();
	mode.setModeName(operatingMode);
	mode.setAllowedDeviceList(platforms);
	mode.setImageList(directories);
	mode.setNeuralNetworkList(nnlist);
    dispatcher.setMode(mode);
	std::list<std::string> imglist(directories.begin(), directories.end());
    resultManager = dispatcher.dispatchImages(imglist);
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(Result result) {
    page.setResult(result);
}    
    