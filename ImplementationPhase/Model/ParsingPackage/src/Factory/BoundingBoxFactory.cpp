#include "BoundingBox.hpp"
#include "ClassProbability.hpp"
#include "BoundingBoxFactory.hpp"

#include <list>

BoundingBox BoundingBoxFactory::build(float x, float y, float width, float height, std::list<ClassProbability> probabilities)
{
    return BoundingBox(x, y, width, height, probabilities);
}