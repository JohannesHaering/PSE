#include <vector>
#include <assert.h>
#include "ViewFacade.hpp"
#include "TrainingPanel.hpp"
#include "NewTrainStepHandler.hpp"


NewTrainStepHandler::NewTrainStepHandler() : page(ViewFacade::getInstance()->getTrainingPanel()) { }

/*
* Calls the view to display more training points.
* Paramaters:
* -training: the training y-values
* -test: the testing y-values
* Training and test must be the same size
*/
void NewTrainStepHandler::newAccuracyPoints(std::vector<float> training, std::vector<float> test) {
    page->newTrainingFinished(training, test);
}
