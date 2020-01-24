#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"
#include "HighEfficiencyMode.hpp"
#include "LowPowerMode.hpp"
#include "HighPerformanceMode.hpp"
#include "MultipleImageFileIO.hpp"
#include "ClassificationResult.hpp"
#include "ResultFacade.hpp"
#include <opencv2/opencv.hpp>

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
    page.startEnable(canStart());
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
	std::list<Device> platformlist(platforms.begin(), platforms.end());
	std::list<std::string> dirlist(directories.begin(), directories.end());
    int opMode = page.getOperatingMode();
	Mode* mode;
	if (opMode == 0) 
	{
		mode = new HighEfficiencyMode();
	}
	else if (opMode == 1)
	{
		mode = new LowPowerMode();
	}
	else
	{
		mode = new HighPerformanceMode();
	}
	mode->setAllowedDeviceList(platformlist);
	mode->setNeuralNetworkList(nnlist);
    dispatcher.setMode(mode);
	MultipleImageFileIO* io = new MultipleImageFileIO();	
	std::list<std::string> dirList(directories.begin(), directories.end());
	Data<std::list<cv::Mat>> imageList = io->readFile(dirList);
	
	//images.insert(directories.begin(), imageList.getData().begin());
    resultManager = dispatcher.dispatchImages(imageList.getData());
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(std::string nn_id, std::string input_id) {
	ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(nn_id, input_id);
	
    //page.resultsChanged(result->getNeuralNetworkID, result->getImageID, );
}    
    

/*
* Finds the given result and calls the model to save it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributor::saveResult(std::string neuralNetworkId, std::string imageId, std::string path)
{
	ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(neuralNetworkId, imageId);
	ResultFacade model = ResultFacade();
	model.writeClassificationResult(*result, path);
}