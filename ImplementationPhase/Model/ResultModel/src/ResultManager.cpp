#include <list>
#include <string>
#include <map>
#include "Result.h"

using namespace std;

class ResultManager {
	public:
		ResultManager(list<Result> resultList) : resultList(resultList){} 
		list<Result> getResultsByImage(string imageID) 
		{
			resultList = list<Result>();
			auto it = imageMap.find(imageID);
			while (it != imageMap.end()) 
			{
				Result* newRes = it->second;
				resultList.push_back(*newRes);
				std::next(it);
			}
			return resultList;
		};

		list<Result> getResultsByNeuralNetwork(string neuralNetworkID)
		{
			resultList = list<Result>();
			auto it = imageMap.find(neuralNetworkID);
			while (it != imageMap.end()) {
				resultList.push_back(*(it->second));
				std::next(it);
			}
			return resultList;
		};

		Result* getSingleResult(string imageID, string neuralNetworkID) 
		{
			auto it = imageMap.find(imageID);
			while (it != imageMap.end()) {
				if (it->first == neuralNetworkID) 
					return it->second;
			}
			return nullptr; //result not found
		};

		void addResult(Result result) 
		{
			organizeResults(result);
		};

		void addResults(list<Result> results) 
		{
			for (std::list<Result>::iterator it = results.begin(); it != results.end(); it++) {
				organizeResults(*it);
			}
		};

	private:
		list<Result> resultList;
		map<string,Result*> neuralNetworkMap;
		map<string,Result*> imageMap;
		void organizeResults(Result result) 
		{
			resultList.push_back(result);
			auto newNNEntry = std::pair<string, Result*>(result.GetNeuralNetworkID(), &resultList.back());
			auto newImageEntry = std::pair<string, Result*>(result.GetImageID(), &resultList.back());
			neuralNetworkMap.insert(newNNEntry);
			imageMap.insert(newImageEntry);
		};
};
