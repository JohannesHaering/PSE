#include "ClassProbability.hpp"
#include "ClassProbabilityFactory.hpp"

#include <string>

ClassProbability ClassProbabilityFactory::build(std::string classId, float probability)
{
    return ClassProbability(classId, probability);
}
