#include "../../../ResultModel/include/BoundingBox.h"
#include "../../../ResultModel/include/DetectionResult.h"
#include "../../include/Factory/DetectionResultFactory.h"

#include <string>

using namespace std;

DetectionResult DetectionResultFactory::build(string imageId, string neuralnetworkId, list<BoundingBox> boundingBoxes){
    return DetectionResult(imageId, neuralnetworkId, boundingBoxes);
} 