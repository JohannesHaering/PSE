#ifndef RESULT_MANAGER_H_
#define RESULT_MANAGER_H_

#include <list>
#include <string>
#include <map>
#include "Result.hpp"

class ResultManager {
	public:
		ResultManager();
		ResultManager(std::list<Result*> resultList);
		Result* getSingleResult(std::string imageID, std::string neuralNetworkID);
		void addResult(Result* result);
		void addResults(std::list<Result*> results);

	private:
    std::map<std::string, Result*> resultMap;
		void organizeResults(Result* result);
};
#endif
