#ifndef CLASSIFICATION_RESULT_H
#define CLASSIFICATION_RESULT_H
#include <string>
#include <list>
#include <ClassProbability.h>
#include "Result.h"

using namespace std;

class ClassificationResult : public Result{
	public:
   		ClassificationResult(string imageID, string neuralNetworkID, list<ClassProbability> classProbabilityList);
		list<ClassProbability> GetProbabilities();
	private:
		list<ClassProbability> classProbabilityList;
};
#endif
