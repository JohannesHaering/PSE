#ifndef NEW_TRAIN_STEP_HANDLER_H_
#define NEW_TRAIN_STEP_HANDLER_H_

#include <vector>
#include <assert.h>
#include "viewfacade.h"
#include "training.h"

class NewTrainStepHandler {
    
    public: 
        NewTrainStepHandler();
        void newAccuracyPoints(std::vector<float> training, std::vector<float> test);

    private: 
        Training* page;    

};
#endif