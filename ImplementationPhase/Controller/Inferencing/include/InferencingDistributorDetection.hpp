#ifndef INFERENCING_DISTRIBUTOR_DETECTION_H_
#define INFERENCING_DISTRIBUTOR_DETECTION_H_

#include "InferencingDistributor.hpp"

class InferencingDistributorDetection : public InferencingDistributor {

    public: 
        InferencingDistributorDetection();
        void enableStart();

    protected: 
        void drawResult(Result result);

};
#endif