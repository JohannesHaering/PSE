#ifndef NEW_TRAIN_STEP_HANDLER_H_
#define NEW_TRAIN_STEP_HANDLER_H_

#include <vector>
#include <assert.h>
#include "ViewFacade.hpp"
#include "TrainingPanel.hpp"

class NewTrainStepHandler {

    public:
        NewTrainStepHandler();
        void newAccuracyPoints(std::vector<float> training, std::vector<float> test);

    private:
        TrainingPanel* page;

};
#endif
