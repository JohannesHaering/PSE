#include "Pager.hpp"
#include "NextHandler.hpp"
#include "ViewFacade.hpp"
#include "ControllerFacade.hpp"
#include <stdexcept>


NextHandler::NextHandler(Pager* pager)    
{ 
	  this->pager = pager;
}

/*
* Handles the event if a next button was clicked.
* Calls the next() function of the referenced Pager.
*/
void NextHandler::onAction() 
{
	try 
	{
		pager->next();
		ControllerFacade::getInstance()->updateResultsClassification();
	}
	catch (const std::invalid_argument& ia)
	{
		pager->getGUIPage()->showError("No next exists");
	}
	
}
