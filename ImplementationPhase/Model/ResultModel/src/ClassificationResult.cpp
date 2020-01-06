#include <string>
#include <list>
#include <ClassProbability.h>

using namespace std;

class ClassificationResult : public Result{
	public:
   		ClassificationResult(string imageID, string neuralNetworkID, list<ClassProbability> classProbabilityList) {
			this.imageID = imageID;
			this.neuralNetworkID = neuralNetworkID;
			this.classProbabilityList = classProbabilityList;
		}
		list<ClassProbability> GetProbabilities() {
			return classProbabilityList;
		}
	private:
		list<ClassProbability> classProbabilityList;
}


