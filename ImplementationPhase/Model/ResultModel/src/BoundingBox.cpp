#include <list>
#include <ClassProbability.h>

using namespace std;

Class BoundingBox{
	public:
		BoundingBox(float x, float y, float width, float height) {
			this.x = x;
			this.y = y;
			this.width = width;
			this.height = height;
		}
		float getX() {
			return x;
		}
		float getY() {
			return y;
		}
		float getWidth() {
			return width;
		}
		float getHeight() { 
			return height;
		}
		list<ClassProbabilities> getProbabilities() {
			return classProbabilityList;

	private:
		float x, y;
		float width, height;
		list<ClassProbability> classProbabilityList;
}
