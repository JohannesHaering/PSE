#ifndef DETECTION_RESULT_H_
#define DETECTION_RESULT_H_

#include <string>
#include <list>
#include "Result.hpp"
#include "BoundingBox.hpp"

class DetectionResult : public Result{
	public:
   		DetectionResult(std::string imageID, std::string neuralNetworkID, std::list<BoundingBox> boundingBoxList);
		std::list<BoundingBox> getBoundingBoxes();
	private:
		std::list<BoundingBox> boundingBoxList;
};
#endif
