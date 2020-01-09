#include <list>
#include <string>
#include <map>
#include "Result.hpp"
#include "ResultManager.hpp"

//using namespace std;

ResultManager::ResultManager(std::list<Result> resultList) : resultList(resultList){}

std::list<Result> ResultManager::getResultsByImage(std::string imageID) 
{
	resultList = std::list<Result>();
	auto it = imageMap.find(imageID);
	while (it != imageMap.end()) 
	{
		Result* newRes = it->second;
		resultList.push_back(*newRes);
		++it;
	}
	return resultList;
};


std::list<Result> ResultManager::getResultsByNeuralNetwork(std::string neuralNetworkID)
{
	resultList = std::list<Result>();
	auto it = neuralNetworkMap.find(neuralNetworkID);
	while (it != imageMap.end()) {
		resultList.push_back(*(it->second));
		++it;
	}
	return resultList;
};

Result* ResultManager::getSingleResult(std::string imageID, std::string neuralNetworkID) 
{
	auto it = imageMap.find(imageID);
	while (it != imageMap.end()) {
		if (it->first == neuralNetworkID) 
			return it->second;
	}
	return nullptr; //result not found
};

void ResultManager::addResult(Result result) 
{
	organizeResults(result);
};

void ResultManager::addResults(std::list<Result> results) 
{
	for (std::list<Result>::iterator it = results.begin(); it != results.end(); ++it) {
		organizeResults(*it);
	}
};

void ResultManager::organizeResults(Result result) 
{
	resultList.push_back(result);
	auto newNeuralNetworkEntry = std::pair<std::string, Result*>(result.getNeuralNetworkID(), &resultList.back());
	auto newImageEntry = std::pair<std::string, Result*>(result.getImageID(), &resultList.back());
	neuralNetworkMap.insert(newNeuralNetworkEntry);
	imageMap.insert(newImageEntry);
};
