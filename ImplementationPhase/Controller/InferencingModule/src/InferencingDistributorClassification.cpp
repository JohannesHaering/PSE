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
#include "ControllerFacade.hpp"
#include <iostream>

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
    DispatchManager& dispatcher = DispatchManager::getInstance();
    dispatcher.setNeuralNetworkList(neuralNetworks);
    std::vector<Device> platforms = page->getDevices();
	std::list<Device> platformlist(platforms.begin(), platforms.end());
	std::list<std::string> dirlist(directories.begin(), directories.end());
    int opMode = page->getOperatingMode();
    std::list<cv::Mat> imglist = ImageFacade().getImages(dirlist, 0, 0, 0);
    images = std::vector<cv::Mat>(imglist.begin(), imglist.end());
	Mode* mode;
	if (opMode == 0) 
	{
		mode = new HighPerformanceMode();
	}
	else if (opMode == 1)
	{
		mode = new HighEfficiencyMode();
	}
	else
	{
		mode = new LowPowerMode();
	}
	mode->setAllowedDeviceList(platformlist);
  std::list<NeuralNetworkAdapter> neuralNetworkList = std::list<NeuralNetworkAdapter>(neuralNetworks.begin(), neuralNetworks.end());
  mode->setNeuralNetworkList(neuralNetworkList);

    dispatcher.setMode(mode);
    resultManager = dispatcher.dispatchImages(directories);
    ControllerFacade::getInstance()->newResultClassification();
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorClassification::drawResult(int neuralNetworkId, int imageId) {
  std::string nn_id = neuralNetworks[neuralNetworkId].getName();
  std::string img_id = directories[imageId];
  ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(img_id, nn_id);
  std::string id = result->getImageID();
  page->resultsChanged(result->getNeuralNetworkID(), result->getImageID(), images[imageId], *result);
  
  //page->saveResultEnable(true);
  page->update();
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
	std::string img_id = directories[imageId];
	ClassificationResult* result = (ClassificationResult*)resultManager.getSingleResult(img_id, nn_id);
	ResultFacade model = ResultFacade();
	model.writeClassificationResult(*result, path);
}

