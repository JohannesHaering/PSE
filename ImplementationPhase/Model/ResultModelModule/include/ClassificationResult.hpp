#ifndef CLASSIFICATION_RESULT_H_
#define CLASSIFICATION_RESULT_H_
#include <string>
#include <list>
#include "ClassProbability.hpp"
#include "Result.hpp"

using namespace std;

class ClassificationResult : public Result{
	public:
   		ClassificationResult(string imageID, string neuralNetworkID, list<ClassProbability> classProbabilityList);
		list<ClassProbability> getProbabilities();
	private:
		list<ClassProbability> classProbabilityList;
};
#endif
