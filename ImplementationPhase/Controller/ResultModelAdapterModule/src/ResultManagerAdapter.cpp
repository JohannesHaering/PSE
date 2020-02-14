#include <list>
#include <string>
#include <map>
#include "Result.hpp"
#include "ResultManagerAdapter.hpp"

ResultManagerAdapter::ResultManagerAdapter(ResultManager resultManager) : resultManager(resultManager){}

std::list<Result*> ResultManagerAdapter::getResultsByImage(std::string imageID)
{
	return resultManager.getResultsByImage(imageID);
};


std::list<Result*> ResultManagerAdapter::getResultsByNeuralNetwork(std::string neuralNetworkID)
{
	return resultManager.getResultsByNeuralNetwork(neuralNetworkID);
};

Result* ResultManagerAdapter::getSingleResult(std::string imageID, std::string neuralNetworkID)
{
	return resultManager.getSingleResult(imageID, neuralNetworkID);
};

void ResultManagerAdapter::addResult(Result* result)
{
	resultManager.addResult(result);
};

void ResultManagerAdapter::addResults(std::list<Result*> results)
{
	resultManager.addResults(results);
};

