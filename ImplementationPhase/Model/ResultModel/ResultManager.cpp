#include <list>
#include <stringi>
#include <map>
#include <Result>

using namespace std;

class ResultManager {
	public:
		ResultManager(list<Result> resultList) {
			this.resultList = resultList;
		}
		list<Result> getResultsByImage(string imageID) {
			resultList = list<Result>();
			it = imageMap.find(imageID);
			while (it != imageMap.end()) {
				resultList.append(*(it->first));
				std::next(it);
			}
			return resultList;
		}

		list<Result> getResultsByNeuralNetwork(string neuralNetworkID);
			resultList = list<Result>();
			it = imageMap.find(neuralNetworkID);
			while (it != imageMap.end()) {
				resultList.append(*(it->first));
				std::next(it);
			}
			return resultList;
		}

		Result getSingleResult(string imageID, string neuralNetworkID) {
			it = imageMap.find(imageID);
			while (it != imageMap.end()) {
				if (it->first.getNeuralNetworkID == neuralNetworkID) 
					return it->first;
			}
			return NULL; //result not found
		void addResult(Result result) {
			organizeResults(result);
		}

		void addResults(list<Result> results) {
			for (it = results.begin(); it != results.end(); it++) {
				organizeResults(*it);
			}
		}

	private:
		list<Result> resultList;
		map<string,*Result> neuralNetworkMap;
		map<string,*Result> imageMap;
		void organizeResults(Result result) {
			resultList.push_back(result);
			neuralNetworkMap.insert(std::pair<string, *Result>(result.GetNeuralNetworkID(), &resultList.back());
			imageMap.insert(std::pair<string, *Result>(result.GetImageID(), &resultList.back());
		}
}
