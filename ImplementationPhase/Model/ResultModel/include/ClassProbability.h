#include <string>

using namespace std;

Class ClassProbability{
	public:
		NetworkPrediction(string name, float probability);
		string getClassName();
		string getProbability();
	private:
		string className;
		float probability;
}

