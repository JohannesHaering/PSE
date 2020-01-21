#include <vector>
#include <assert.h>
#include "viewfacade.h"
#include "TrainingPage.hpp"
#include "NewTrainStepHandler.hpp"


NewTrainStepHandler::NewTrainStepHandler() : page(ViewFacade::getTrainingPage()) { }

/*
* Calls the view to display more training points.
* Paramaters:
* -training: the training y-values 
* -test: the testing y-values
* Training and test must be the same size
*/
void NewTrainStepHandler::newAccuracyPoints(std::vector<float> training, std::vector<float> test) {
    assert(training.size() == test.size());
    page.newTrainingFinished(training, test);          
}
