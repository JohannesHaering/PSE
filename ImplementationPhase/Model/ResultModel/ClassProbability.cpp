#include <string>

using namespace std;

Class ClassProbability{
	public:
		NetworkPrediction(string name, float probability) {
			if (probability < 0 or probability > 1):
				throw std::range_error("probability should be between 0.0 and 1.0, was %f\n", probability);
			className = name;
			this.probability = probability;
		}
		string getClassName() {
			return className;
		}
		string getProbability() {
			return probability;
		}
	private:
		string className;
		float probability;
}

