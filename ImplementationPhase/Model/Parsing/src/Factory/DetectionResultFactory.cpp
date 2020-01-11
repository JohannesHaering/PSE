#include "BoundingBox.hpp"
#include "DetectionResult.hpp"
#include "DetectionResultFactory.hpp"

#include <string>
#include <list>

DetectionResult DetectionResultFactory::build(std::string imageId, std::string neuralnetworkId, std::list<BoundingBox> boundingBoxes)
{
    return DetectionResult(imageId, neuralnetworkId, boundingBoxes);
}