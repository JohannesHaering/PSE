#include <string>
#include <list>
#include "BoundingBox.hpp"
#include "DetectionResult.hpp"

using namespace std;

DetectionResult::DetectionResult(string imageID, string neuralNetworkID, list<BoundingBox> boundingBoxList) :
	Result(imageID, neuralNetworkID), boundingBoxList(boundingBoxList) {}

list<BoundingBox> DetectionResult::GetBoundingBoxes() { return boundingBoxList; }
