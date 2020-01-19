#include "Pager.hpp"
#include "PrevHandler.hpp"
#include "ViewFacade.hpp"
#include <stdexcept>

PrevHandler::PrevHandler(Pager pager) : pager(pager) {}
        
/*
* Calls the prev() function of the referenced Pager.
*/
void PrevHandler::prev() 
{
	try 
	{
		pager.prev();
	}
	catch (const std::invalid_argument& ia)
	{
		ViewFacade::getInstance().exceptionText("No previous exists");
	}

}
