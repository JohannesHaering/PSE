#ifndef RESULT_MANAGER_H
#define RESULT_MANAGER_H

#include <list>
#include <string>
#include <map>
#include "Result.h"

class ResultManager {
	public:
		ResultManager(list<Result> resultList);
		std::list<Result> getResultsByImage(string imageID);
		std::list<Result> getResultsByNeuralNetwork(string neuralNetworkID);
		Result* getSingleResult(string imageID, string neuralNetworkID);
		void addResult(Result result);
		void addResults(list<Result> results);

	private:
		void organizeResults(Result result);
		std::list<Result> resultList;
		std::map<string,Result*> neuralNetworkMap;
		std::map<string,Result*> imageMap;
};
#endif
