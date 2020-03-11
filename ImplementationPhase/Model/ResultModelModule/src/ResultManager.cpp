#include <list>
#include <string>
#include <map>
#include "Result.hpp"
#include "ResultManager.hpp"
#include <iostream>

ResultManager::ResultManager() 
{
		resultMap = std::map<std::string, Result*>();
}

ResultManager::ResultManager(std::list<Result*> resultList) //: resultList(resultList)
{
		resultMap = std::map<std::string, Result*>();
    for (auto res : resultList) organizeResults(res);
}


Result* ResultManager::getSingleResult(std::string imageID, std::string neuralNetworkID) 
{
	auto it = resultMap.find(neuralNetworkID + imageID);
  std::cout << "printing key " <<neuralNetworkID + imageID << " key ended" << std::endl;
	if (it != resultMap.end()) {
		return it->second;
	}
	return nullptr; //result not found
};

void ResultManager::addResult(Result* result) 
{
	organizeResults(result);
};

void ResultManager::addResults(std::list<Result*> results) 
{
	for (std::list<Result*>::iterator it = results.begin(); it != results.end(); ++it) {
		organizeResults(*it);
	}
};

void ResultManager::organizeResults(Result* result) 
{
  auto tmp = std::pair<std::string, Result*>(result->getNeuralNetworkID() + result->getImageID(), result);
	resultMap.insert(tmp);
};
