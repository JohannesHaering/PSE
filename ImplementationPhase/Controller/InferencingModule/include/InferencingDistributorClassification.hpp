#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"
#include "InferencePageAdapter.hpp"

class InferencingDistributorClassification : virtual public InferencingDistributor {

    public: 
        InferencingDistributorClassification(InferencePageAdapter page);
        void enableStart();
        void startProcess();
		void saveResult(std::string neuralNetworkId, std::string imageId, std::string path);

    protected: 
        void drawResult(std::string nn_id, std::string input_id);

};
#endif