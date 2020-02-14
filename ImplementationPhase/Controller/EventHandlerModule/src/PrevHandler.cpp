#include "Pager.hpp"
#include "PrevHandler.hpp"
#include "ViewFacade.hpp"
#include "ControllerFacade.hpp"
#include <stdexcept>

PrevHandler::PrevHandler(Pager* pager) 
{
	this->pager = pager;
}
        
/*
* Calls the prev() function of the referenced Pager.
*/
void PrevHandler::onAction()
{
	try 
	{
		pager->prev();
		ControllerFacade::getInstance()->updateResultsClassification();
	}
	catch (const std::invalid_argument& ia)
	{
		pager->getGUIPage()->showError("No previous exists");
	}

}
