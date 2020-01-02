#include <list>
#include <ClassProbability.h>

using namespace std;

Class BoundingBox{
	public:
		BoundingBox(float x, float y, float width, float height);
		float getX();
		float getY();
		float getWidth();
		float getHeight();
		list<ClassProbabilities> getProbabilities();

	private:
		float x, y;
		float width, height;
		list<ClassProbability> classProbabilityList;
}
