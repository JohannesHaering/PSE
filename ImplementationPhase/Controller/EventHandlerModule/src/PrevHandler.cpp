#include "Pager.hpp"
#include "PrevHandler.hpp"
#include "ViewFacade.hpp"
#include <stdexcept>

PrevHandler::PrevHandler(Pager *pager) 
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
	}
	catch (const std::invalid_argument& ia)
	{
		pager->getGUIPage()->showError("No previous exists");
	}

}
