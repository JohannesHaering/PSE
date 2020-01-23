#ifndef CLASSIFICATION_RESULT_FACTORY_H_
#define CLASSIFICATION_RESULT_FACTORY_H_

#include "ClassProbability.hpp"
#include "ClassificationResult.hpp"

#include <string>
#include <list>

class ClassificationResultFactory
{
public:
    ClassificationResult build(std::string imageId, std::string neuralNetworkId, std::list<ClassProbability> probabilities);
};
#endif
