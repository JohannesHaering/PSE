#ifndef BOUNDING_BOX_H_
#define BOUNDING_BOX_H_
#include <list>
#include "ClassProbability.hpp"

class BoundingBox{
	public:
		BoundingBox(float x, float y, float width, float height, std::list<ClassProbability> classProbabilityList);
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		std::list<ClassProbability> getProbabilities();

	private:
		float x, y;
		float width, height;
		std::list<ClassProbability> classProbabilityList;
};
#endif
