#include "../../../ResultModel/include/BoundingBox.h"
#include "../../../ResultModel/include/ClassProbability.h"
#include "../../include/Factory/BoundingBoxFactory.h"

#include <string>
#include <list>

using namespace std;

BoundingBox BoundingBoxFactory::build(float x, float y, float width, float height, list<ClassProbability> probabilities){
    return BoundingBox(x, y, width, height, probabilities);
}