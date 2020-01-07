#ifndef CLASS_PROBABILITY_FACTORY_H
#define CLASS_PROBABILITY_FACTORY_H

#include "../../../ResultModel/include/ClassProbability.h"

#include <string>

using namespace std;

class ClassProbabilityFactory{
    public:
        ClassProbability build(string classId, float probability);
};
#endif