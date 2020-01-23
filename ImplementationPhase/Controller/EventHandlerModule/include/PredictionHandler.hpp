#ifndef PREDICTION_HANDLER_H_
#define PREDICTION_HANDLER_H_

#include "viewfacade.h"
#include "ResultManager.hpp"
#include "PerformancePredictorFromFile.hpp"
#include "PowerPredictorFromFile.hpp"
#include "inferencepageadapter.h"

class PredictionHandler 
{
    public: 
		PredictionHandler(InferencePageAdapter page);
		PredictionHandler();
		void onAction();

    private: 
		PowerPredictorFromFile powerPredictor;
		PerformancePredictorFromFile performancePredictor;
		InferencePageAdapter page;

};
#endif