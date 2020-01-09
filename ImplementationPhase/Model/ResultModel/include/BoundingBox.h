#ifndef BOUNDING_BOX_H_
#define BOUNDING_BOX_H_
#include <list>
#include "ClassProbability.h"

using namespace std;

class BoundingBox{
	public:
		BoundingBox(float x, float y, float width, float height, list<ClassProbability> classProbabilityList);
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		list<ClassProbability> getProbabilities();

	private:
		float x, y;
		float width, height;
		list<ClassProbability> classProbabilityList;
};
#endif
