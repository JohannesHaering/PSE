#ifndef CLASS_PROBABILITY_H
#define CLASS_PROBABILITY_H
#include <string>

using namespace std;

class ClassProbability{
	public:
		ClassProbability(string name, float probability);
		string getClassName();
		float getProbability();
	private:
		string className;
		float probability;
};
#endif
