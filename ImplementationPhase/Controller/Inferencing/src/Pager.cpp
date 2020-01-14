#include "ViewFacade.hpp"
#include "InferencingDistributor.hpp"
#include "Pager.hpp"

/*
* Resets the Pager and sets a new maximum of pages.
* Parameters: 
* -int maxPage: the new maximum number of pages
*/
void Pager::reset(int maxPage) 
{
	this->maxPage = maxPage;
	currentPage = 0; 
	this->disable();
}

/*
* Increments the page number and checks for disables.
*/
void Pager::next() 
{
    currentPage++;
    disable();
}

/*
* Decrements the page number and checks for disables.
*/
void Pager::prev() 
{
    currentPage--;
    disable();
}

/*
* Returns the current Page.
*/
int Pager::getCurrentPage() 
{
	return currentPage;
}

/*
* Returns if the nextButton should be enabled.
*/
bool Pager::nextEnable()
{
	return currentPage + 1 < maxPage;
}

/*
* Returns if the prevButton should be enabled.
*/
bool Pager::prevEnable()
{
	return currentPage > 0;
}