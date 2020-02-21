#include "ClassificationResultFactory.hpp"
#include "ClassProbability.hpp"
#include "ClassificationResult.hpp"

#include <string>
#include <list>

ClassificationResult* ClassificationResultFactory::build(std::string imageId, std::string neuralNetworkId, std::list<ClassProbability> probabilities)
{
    return new  ClassificationResult(imageId, neuralNetworkId, probabilities);
}
