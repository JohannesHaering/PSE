#include <string>
#include <list>
#include <BoundingBox.h>

using namespace std;

class DetectionResult : public Result{
	public:
   		DetectionResult(string imageID, string neuralNetworkID, list<BoundingBox> boundingBoxList);
		list<BoundingBox> GetBoundingBoxes();
	private:
		list<BoundingBox> boundingBoxList;
	
}


