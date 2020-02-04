#include "InferencingDistributor.hpp"
#include "NeuralNetworkPager.hpp"
#include "ImagePager.hpp"
#include "SaveResultHandler.hpp"
#include "NewResultHandler.hpp"

/**
 * Creates a NewResultHandler.
 * Parameters:
 * -InferencingDistributor distributor: The distributor the new result is from
 * -NeuralNetworkPager nnpager: The
 * -ImagePager ipager
 */
NewResultHandler::NewResultHandler(InferencingDistributor* distributor, NeuralNetworkPager *nnpager, ImagePager *ipager) :
SaveResultHandler(distributor, nnpager, ipager) 
{ }

/*
* Resets the pagers and class the distributor to draw the first result.
*/ 
void NewResultHandler::onAction(){
    int amountimg = distributor->getAmountImages();
    int amountnn = distributor->getAmountNeuralNetworks();
    ipager->reset(amountimg);
    nnpager->reset(amountnn);
    distributor->drawResult(0,0);
}
