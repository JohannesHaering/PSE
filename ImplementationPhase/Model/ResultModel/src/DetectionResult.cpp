#include <string>
#include <list>
#include <BoundingBox.h>

using namespace std;

class DetectionResult : public Result{
	public:
   		DetectionResult(string imageID, string neuralNetworkID, list<BoundingBox> boundingBoxList) {
			this.imageID = imageID;
			this.neuralNetworkID = neuralNetworkID;
			this.boundingBoxList = boundingBoxList;
		}

		list<BoundingBox> GetBoundingBoxes() {
			return boundingBoxList;
		}

	private:
		list<BoundingBox> boundingBoxList;
}


