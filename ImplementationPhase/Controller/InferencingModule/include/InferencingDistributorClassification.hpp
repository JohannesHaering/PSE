#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"
#include "inferencepageadapter.h"

class InferencingDistributorClassification : virtual public InferencingDistributor {

    public: 
        InferencingDistributorClassification(InferencePageAdapter page);
        void enableStart();
        void startProcess();

    protected: 
        void drawResult(Result result);        

};
#endif