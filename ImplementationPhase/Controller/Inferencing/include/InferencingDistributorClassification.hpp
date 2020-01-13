#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"

class InferencingDistributorClassification : public InferencingDistributor {

    public: 
        InferencingDistributorClassification();
        void enableStart();
        void startProcess();

    protected: 
        void drawResult(Result result);        

};
#endif