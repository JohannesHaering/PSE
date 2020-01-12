#ifndef PREDICTION_HANDLER_H_
#define PREDICTION_HANDLER_H_

#include "ViewFacade.hpp"
#include "ResultManager.hpp"

class PredictionHandler 
{
    public: 
		PredictionHandler(InferencePage page);
		PredictionHandler();
		void onAction();

    private: 
		PowerPredictorFromFile powerPredictor;
		PerformancePredictorFromFile performancePredictor;
		InferencePage page;

};
#endif