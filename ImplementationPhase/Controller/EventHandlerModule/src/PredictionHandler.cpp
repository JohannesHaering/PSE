#include "ViewFacade.hpp"
#include "ResultManager.hpp"
#include "DispatchManager.hpp"
#include "PredictionHandler.hpp"
#include "PowerPredictorFromFile.hpp"
#include "PerformancePredictorFromFile.hpp"
#include "InferencePageAdapter.hpp"
#include <list>

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
	std::list<std::string> devicelist;

	for (std::vector<Device>::iterator it = devices.begin(); it != devices.end(); ++it) {
		devicelist.push_back(it->getName());
	}

	std::map<std::string, float> performancePredictionValues = performancePredictor.predict(devicelist);
	std::map<std::string, float> powerPredictionValues = powerPredictor.predict(devicelist);

	float performancePrediction = 0;
	float powerPrediction = 0;

	std::map<std::string, float>::iterator it = performancePredictionValues.begin();
	while (it != performancePredictionValues.end())
	{
		performancePrediction += it->second;
	}

	std::map<std::string, float>::iterator iterator = powerPredictionValues.begin();
	while (iterator != powerPredictionValues.end())
	{
		powerPrediction += iterator->second;
	}

    page.setPerformancePrediction(performancePrediction);
    page.setPowerPrediction(powerPrediction);

	page.update();
}