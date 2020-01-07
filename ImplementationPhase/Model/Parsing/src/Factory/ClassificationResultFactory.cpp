#include "../../include/Factory/ClassificationResultFactory.h"
#include "../../../ResultModel/include/ClassProbability.h"
#include "../../../ResultModel/include/ClassificationResult.h"

#include <string>
#include <list>

using namespace std;

ClassificationResult ClassificationResultFactory::build(string imageId, string neuralNetworkId, list<ClassProbability> probabilities) {
    return ClassificationResult(imageId, neuralNetworkId, probabilities);
}