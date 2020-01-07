#ifndef CLASSIFICATION_RESULT_FACTORY
#define CLASSIFICATION_RESULT_FACTORY

#include "../../../ResultModel/include/ClassProbability.h"
#include "../../../ResultModel/include/ClassificationResult.h"

#include <string>
#include <list>

using namespace std;

class ClassificationResultFactory {
    public:
        ClassificationResult build(string imageId, string neuralNetworkId, list<ClassProbability> probabilities);
};
#endif
