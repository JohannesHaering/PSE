#ifndef CLASS_PROBABILITY_FACTORY_H_
#define CLASS_PROBABILITY_FACTORY_H_

#include "ClassProbability.hpp"

#include <string>

class ClassProbabilityFactory
{
public:
    ClassProbability build(std::string classId, float probability);
};
#endif