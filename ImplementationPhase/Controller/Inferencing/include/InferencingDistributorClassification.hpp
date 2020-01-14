#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"

class InferencingDistributorClassification : public InferencingDistributor {

    public: 
        InferencingDistributorClassification(InferencePage page);
        void enableStart();
        void startProcess();

    protected: 
        void drawResult(Result result);        

};
#endif