#include "InferencingDistributor.hpp"
#include "InferencingDistributorClassification.hpp"
#include "HighEfficiencyMode.hpp"
#include "LowPowerMode.hpp"
#include "HighPerformanceMode.hpp"
#include "MultipleImageFileIO.hpp"
#include "ClassificationResult.hpp"
#include "ResultFacade.hpp"
#include "ResultManager.hpp"
#include "ImageFacade.hpp"
#include <opencv2/opencv.hpp>

/*
* Creates a InferencingDistributor for Classification.
* Parameters:
* -Inference page: the corresponding page
*/
InferencingDistributorClassification::InferencingDistributorClassification(InferencePageAdapter* page)
{
	this->page = page;
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorClassification::enableStart(){
    page->startEnable(canStart());
}

/*
* Starts the classification process. 
* Gets information from the view and dispatches the images accordingly.
*/
void InferencingDistributorClassification::startProcess()
{
	std::list<NeuralNetworkAdapter> nnlist(neuralNetworks.begin(), neuralNetworks.end());
    DispatchManager& dispatcher = DispatchManager::getInstance();
    dispatcher.setNeuralNetworkList(nnlist);
    std::vector<Device> platforms = page->getDevices();
	std::list<Device> platformlist(platforms.begin(), platforms.end());
	std::list<std::string> dirlist(directories.begin(), directories.end());
    int opMode = page->getOperatingMode();
    std::list<cv::Mat> imglist = ImageFacade().getImages(dirlist, 0, 0, 0);
    images = std::vector<cv::Mat>(imglist.begin(), imglist.end());
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
    resultManager = dispatcher.dispatchImages(directories);
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(int neuralNetworkId, int imageId) {
	std::string nn_id = neuralNetworks[neuralNetworkId].getName();
	std::string img_id = directories[imageId].erase(0, directories[imageId].find_last_of("/")).erase(directories[imageId].find_last_of("."));
	ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(nn_id, img_id);
    page->resultsChanged(result->getNeuralNetworkID(), result->getImageID(), images[imageId], *result);
}    
    

/*
* Finds the given result and calls the model to save it
* Parameters:
* -int neuralNetworkId: number of neural network of the wanted result
* -int imageId: number if image of the wanted result
*/
void InferencingDistributorClassification::saveResult(int neuralNetworkId, int imageId, std::string path)
{
	std::string nn_id = neuralNetworks[neuralNetworkId].getName();
	std::string img_id = directories[imageId].erase(0, directories[imageId].find_last_of("/")).erase(directories[imageId].find_last_of("."));
	ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(nn_id, img_id);
	ResultFacade model = ResultFacade();
	model.writeClassificationResult(*result, path);
}

