#ifndef CLASSIFICATION_RESULT_H_
#define CLASSIFICATION_RESULT_H_
#include <string>
#include <list>
#include "classprobability.h"
#include "result.h"

class ClassificationResult : public Result{
    public:
        ClassificationResult(std::string imageID, std::string neuralNetworkID, std::list<ClassProbability> classProbabilityList);
        std::list<ClassProbability> getProbabilities();
    private:
        std::list<ClassProbability> classProbabilityList;
};
#endif
