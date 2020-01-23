#ifndef DETECTION_RESULT_FACTORY_H_
#define DETECTION_RESULT_FACTORY_H_

#include "BoundingBox.hpp"
#include "DetectionResult.hpp"

#include <string>
#include <list>

class DetectionResultFactory
{
public:
    DetectionResult build(std::string imageId, std::string neuralNetworkId, std::list<BoundingBox> boundingBoxes);
};
#endif