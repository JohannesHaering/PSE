#ifndef INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_
#define INFERENCING_DISTRIBUTOR_CLASSIFICATION_H_

#include "InferencingDistributor.hpp"
#include "InferencePageAdapter.hpp"
//#include "ImageFacade.hpp"
#include "opencv2/opencv.hpp"

class InferencingDistributorClassification : virtual public InferencingDistributor {

    public: 
        InferencingDistributorClassification(InferencePageAdapter *page);
        void enableStart() override;
        void startProcess() override;
        void saveResult(int neuralNetworkId, int imageId, std::string path) override;
        void drawResult(int neuralNetworkId, int imageId) override;

    protected: 
		std::vector<cv::Mat> images;
};
#endif
