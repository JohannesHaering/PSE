#include "UpdateResultHandler.hpp"

UpdateResultHandler::UpdateResultHandler(InferencingDistributor* distributor, NeuralNetworkPager* nnpager, ImagePager* ipager) : 
SaveResultHandler(distributor, nnpager, ipager)
{}

/*
* Gets current neuralnetwork and image and calls the distributor to display those.
*/
void SaveResultHandler::onAction()
{
    int nn_id = nnpager->getCurrentPage();
    int img_id = ipager->getCurrentPage();
    distributor->drawResult(nn_id, img_id);
}
