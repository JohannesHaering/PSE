#include "InferencingDistributorDetection.hpp"

InferencingDistributorDetection::InferencingDistributorDetection(InferencePageAdapter page)
{
	this->page = page;
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorDetection::enableStart()
{
    page.startEnable(this->canStart());
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorDetection::drawResult(Result result) 
{
    //page.setResult(result);
}    

