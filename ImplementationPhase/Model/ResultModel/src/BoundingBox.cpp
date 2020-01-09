#include <list>
#include <stdexcept>
#include "ClassProbability.h"
#include "BoundingBox.h"

using namespace std;

BoundingBox::BoundingBox(float x, float y, float width, float height, list<ClassProbability> classProbabilityList) : 
	x(x), y(y), width(width), height(height), classProbabilityList(classProbabilityList)
{
	if (x <= 0 || x >= 1 || y <= 0 || y >= 1 || width <= 0 || width > 1 || height <= 0 || height > 1)
		throw std::invalid_argument("relative should be between 0.0 and 1.0\n");
}

float BoundingBox::getX() { return x; }

float BoundingBox::getY() { return y; }

float BoundingBox::getWidth() { return width; }

float BoundingBox::getHeight() { return height; }

list<ClassProbability> BoundingBox::getProbabilities() { return classProbabilityList; }
