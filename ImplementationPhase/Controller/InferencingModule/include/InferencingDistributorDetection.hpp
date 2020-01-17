#ifndef INFERENCING_DISTRIBUTOR_DETECTION_H_
#define INFERENCING_DISTRIBUTOR_DETECTION_H_

#include "InferencingDistributor.hpp"
#include "Result.hpp"

class InferencingDistributorDetection : public InferencingDistributor {

    public: 
        InferencingDistributorDetection(InferencePage page);
        void enableStart();

    protected: 
        void drawResult(Result result);

};
#endif