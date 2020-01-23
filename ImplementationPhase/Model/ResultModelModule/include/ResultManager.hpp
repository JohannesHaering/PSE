#ifndef RESULT_MANAGER_H_
#define RESULT_MANAGER_H_

#include <list>
#include <string>
#include <map>
#include "Result.hpp"

class ResultManager {
	public:
		ResultManager();
		ResultManager(std::list<Result> resultList);
		std::list<Result> getResultsByImage(std::string imageID);
		std::list<Result> getResultsByNeuralNetwork(std::string neuralNetworkID);
		Result* getSingleResult(std::string imageID, std::string neuralNetworkID);
		void addResult(Result result);
		void addResults(std::list<Result> results);

	private:
		void organizeResults(Result result);
		std::list<Result> resultList;
		std::map<std::string,Result*> neuralNetworkMap;
		std::map<std::string,Result*> imageMap;
};
#endif
