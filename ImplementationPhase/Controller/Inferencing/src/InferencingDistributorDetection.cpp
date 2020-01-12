#include "InferencingDistributorDetection.hpp"

InferencingDistributorDetection::InferencingDistributorDetection() {
    this->view = ViewFacade::getInstance();
}

/*
* Enables or disables the Start button of the View
*/
void InferencingDistributorDetection::enableStart(){
    view.startButtonEnableDetection(this->canStart());
}

/*
* Sends the given result to the view. 
*/
void InferencingDistributorDetection::drawResult(Result result) {
    view.setResultClassification(result);
}    

