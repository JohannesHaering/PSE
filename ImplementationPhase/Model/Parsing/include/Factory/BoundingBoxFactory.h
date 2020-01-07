#ifndef BOUNDING_BOX_FACTORY
#define BOUNDING_BOX_FACTORY

#include "../../../ResultModel/include/BoundingBox.h"
#include "../../../ResultModel/include/ClassProbability.h"

#include <string>
#include <list>

using namespace std;

class BoundingBoxFactory {
    public:
        BoundingBox build(float x, float y, float width, float height, list<ClassProbability> probabilities);
};
#endif
