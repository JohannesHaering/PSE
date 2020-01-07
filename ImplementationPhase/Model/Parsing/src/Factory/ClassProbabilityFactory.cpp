#include "../../../ResultModel/include/ClassProbability.h"
#include "../../include/Factory/ClassProbabilityFactory.h"

#include <string>

using namespace std;

ClassProbability ClassProbabilityFactory::build(string classId, float probability){
    return ClassProbability(classId, probability);
}
