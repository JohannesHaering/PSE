#include "Pager.hpp"
#include "PrevHandler.hpp"
#include "ViewFacade.hpp"
#include <stdexcept>

PrevHandler::PrevHandler(Pager* pager, Pager* otherPager, InferencingDistributorClassification* inferencer) 
{
	this->pager = pager;
  this->otherPager = otherPager;
  this->inferencer = inferencer;
}
        
/*
* Calls the prev() function of the referenced Pager.
*/
void PrevHandler::onAction()
{
	try 
	{
		pager->prev();
    inferencer->drawResult(pager->getCurrentPage(), otherPager->getCurrentPage());
	}
	catch (const std::invalid_argument& ia)
	{
		pager->getGUIPage()->showError("No previous exists");
	}

}
