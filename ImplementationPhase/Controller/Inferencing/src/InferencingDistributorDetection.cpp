#include "InferencingDistributorDetection.hpp"

InferencingDistributorDetection::InferencingDistributorDetection(InferencePage page)
{
	this->page = page;
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorDetection::enableStart()
{
    page.startButtonEnable(this->canStart());
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorDetection::drawResult(Result result) 
{
    page.setResult(result);
}    

