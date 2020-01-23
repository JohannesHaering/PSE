#include "InferencingDistributor.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "SaveResultHandler.hpp"

/**
 * Creates a SaveResultHandler.
 * Parameters:
 * -InferencingDistributor distributor: The distributor the new result is from
 * -NeuralNetworkPager nnpager: The
 * -ImagePager ipager
 */
SaveResultHandler::SaveResultHandler(InferencingDistributor* distributor, NeuralNetworkPager nnpager, ImagePager ipager) : 
distributor(distributor), 
nnpager(nnpager), 
ipager(ipager)
{}

/*
* Gets current neuralnetwork and image and calls the distributor to save those.
*/
void SaveResultHandler::onAction()
{
    int nn_id = nnpager.getCurrentPage();
    int img_id = ipager.getCurrentPage();
	std::string path = distributor->getPage().getSaveFileName();
	distributor->saveResult(std::to_string(nn_id), std::to_string(img_id), path);
}