#ifndef PREDICTION_HANDLER_H_
#define PREDICTION_HANDLER_H_

#include "ViewFacade.hpp"
#include "ResultManager.hpp"
#include "PerformancePredictorFromFile.hpp"
#include "PowerPredictorFromFile.hpp"
#include "InferencePageAdapter.hpp"

class PredictionHandler 
{
    public: 
		PredictionHandler(InferencePageAdapter *page);
		~PredictionHandler();
		void onAction();

    private: 
		PowerPredictorFromFile *powerPredictor;
		PerformancePredictorFromFile *performancePredictor;
		InferencePageAdapter *page;

};
#endif