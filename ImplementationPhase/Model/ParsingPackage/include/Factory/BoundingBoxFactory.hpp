#ifndef BOUNDING_BOX_FACTORY_H_
#define BOUNDING_BOX_FACTORY_H_

#include "BoundingBox.hpp"
#include "ClassProbability.hpp"

#include <list>

class BoundingBoxFactory
{
public:
    BoundingBox build(float x, float y, float width, float height, std::list<ClassProbability> probabilities);
};
#endif
