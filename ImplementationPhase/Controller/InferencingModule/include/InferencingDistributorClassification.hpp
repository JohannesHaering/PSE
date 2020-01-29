#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"
#include "InferencePageAdapter.hpp"
#include "opencv2/opencv.hpp"

class InferencingDistributorClassification : virtual public InferencingDistributor {

    public: 
        InferencingDistributorClassification(InferencePageAdapter *page);
        void enableStart();
        void startProcess();
		void saveResult(int neuralNetworkId, int imageId, std::string path);
		void drawResult(int neuralNetworkId, int imageId);

    protected: 
		std::vector<cv::Mat> images;

};
#endif
