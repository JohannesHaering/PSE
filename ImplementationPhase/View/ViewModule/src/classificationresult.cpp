#include <string>
#include <list>
#include "..\include\classprobability.h"
#include "..\include\classificationresult.h"

ClassificationResult::ClassificationResult(std::string imageID, std::string neuralNetworkID, std::list<ClassProbability> classProbabilityList) :
    Result(imageID, neuralNetworkID), classProbabilityList(classProbabilityList) {}

std::list<ClassProbability> ClassificationResult::getProbabilities() { return classProbabilityList; }
