#include <list>
#include <string>
#include <map>
#include "Result.hpp"
#include "ResultManagerAdapter.hpp"

ResultManagerAdapter::ResultManagerAdapter(ResultManager resultManager) : resultManager(resultManager){}

std::list<Result> ResultManagerAdapter::getResultsByImage(std::string imageID)
{
	return resultManager.getResultByImage(imageID);
};


std::list<Result> ResultManagerAdapter::getResultsByNeuralNetwork(std::string neuralNetworkID)
{
	return resultManager.getResultsByNeuralNetwork(neuralNetworkID);
};

Result ResultManagerAdapter::getSingleResult(std::string imageID, std::string neuralNetworkID)
{
	return resultManager.getSingleResult(neuralNetworkID);
};

void ResultManagerAdapter::addResult(Result result)
{
	resultManager.organizeResults(result);
};

void ResultManagerAdapter::addResults(std::list<Result> results)
{
	for (std::list<Result>::iterator it = results.begin(); it != results.end(); ++it) {
		organizeResults(*it);
	}
};

void ResultManagerAdapter::organizeResults(Result result)
{
	resultList.push_back(result);
	auto newNeuralNetworkEntry = std::pair<std::string, Result*>(result.getNeuralNetworkID(), &resultList.back());
	auto newImageEntry = std::pair<std::string, Result*>(result.getImageID(), &resultList.back());
	neuralNetworkMap.insert(newNeuralNetworkEntry);
	imageMap.insert(newImageEntry);
};
