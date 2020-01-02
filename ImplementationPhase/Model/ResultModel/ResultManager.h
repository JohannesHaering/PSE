#include <list>
#include <stringi>
#include <map>
#include <Result>

using namespace std;

class ResultManager {
	public:
		ResultManager(list<Result> resultList);
		list<Result> getResultsByImage(string imageID);
		list<Result> getResultsByNeuralNetwork();
		Result getSingleResult(string imageID, string neuralNetworkID);
		void addResult(Result result);
		void addResults(list<Result> results);

	private:
		void organizeResults(Result result);
		list<Result> resultList;
		map<string,*Result> neuralNetworkMap;
		map<string,*Result> imageMap;
}
