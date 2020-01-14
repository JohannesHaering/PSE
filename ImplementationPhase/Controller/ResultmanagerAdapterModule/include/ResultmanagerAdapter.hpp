#ifndef RESULT_MANAGER_H_
#define RESULT_MANAGER_H_

#include <list>
#include <string>
#include <map>
#include "ResultManager.hpp"

class ResultManagerAdapter {
	public:
		ResultManagerAdapter(ResultManager resultManager);
		std::list<Result> getResultsByImage(std::string imageID);
		std::list<Result> getResultsByNeuralNetwork(std::string neuralNetworkID);
		Result* getSingleResult(std::string imageID, std::string neuralNetworkID);
		void addResult(Result result);
		void addResults(std::list<Result> results);

	private:
		ResultManager resultManager;
};
#endif
