#ifndef DETECTION_RESULT_H_
#define DETECTION_RESULT_H_

#include <string>
#include <list>
#include "Result.h"
#include "BoundingBox.h"

using namespace std;

class DetectionResult : public Result{
	public:
   		DetectionResult(string imageID, string neuralNetworkID, list<BoundingBox> boundingBoxList);
		list<BoundingBox> getBoundingBoxes();
	private:
		list<BoundingBox> boundingBoxList;
};
#endif
