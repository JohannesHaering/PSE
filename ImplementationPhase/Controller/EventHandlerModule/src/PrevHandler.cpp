#include "Pager.hpp"
#include "PrevHandler.hpp"

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
	catch (const char* msg)
	{

	}

}
