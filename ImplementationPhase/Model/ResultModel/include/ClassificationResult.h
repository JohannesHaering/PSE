#include <string>
#include <list>
#include <ClassProbability.h>

using namespace std;

class ClassificationResult : public Result{
	public:
   		ClassificationResult(string imageID, string neuralNetworkID, list<ClassProbability> classProbabilityList);
		list<ClassProbability> GetProbabilities();
}


