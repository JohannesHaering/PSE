#include <string>
#include <list>
#include "BoundingBox.hpp"
#include "DetectionResult.hpp"

DetectionResult::DetectionResult(std::string imageID, std::string neuralNetworkID, std::list<BoundingBox> boundingBoxList) :
	Result(imageID, neuralNetworkID), boundingBoxList(boundingBoxList) {}

std::list<BoundingBox> DetectionResult::getBoundingBoxes() { return boundingBoxList; }
