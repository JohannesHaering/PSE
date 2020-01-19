#include "viewfacade.h"
#include "ResultManager.hpp"
#include "DispatchManager.hpp"
#include "PredictionHandler.hpp"
#include "PowerPredictorFromFile.hpp"
#include "PerformancePredictorFromFile.hpp"
#include "inferencepageadapter.h"

PredictionHandler::PredictionHandler(InferencePageAdapter page) :
page(page), 
powerPredictor(PowerPredictorFromFile()), 
performancePredictor(PerformancePredictorFromFile()) 
{}

/**
 * Calculates new prediction.
 */ 
void PredictionHandler::onAction(){
	std::vector<Device> devices = page.getDevices();
	float performancePrediction = performancePredictor.predict(devices);
    float powerPrediction = powerPredictor.predict(devices);

    page.setPerformancePrediction(performancePrediction);
    page.setPowerPrediction(powerPrediction);

	page.update();
}