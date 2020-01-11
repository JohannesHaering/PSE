#include <string>
#include <list>
#include <ClassProbability.hpp>
#include <ClassificationResult.hpp>

using namespace std;

ClassificationResult::ClassificationResult(string imageID, string neuralNetworkID, list<ClassProbability> classProbabilityList) : 
	Result(imageID, neuralNetworkID), classProbabilityList(classProbabilityList) {} 

list<ClassProbability> ClassificationResult::GetProbabilities() { return classProbabilityList; }
