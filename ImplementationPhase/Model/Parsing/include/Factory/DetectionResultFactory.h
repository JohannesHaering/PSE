#ifndef DETECTION_RESULT_FACTORY_H
#define DETECTION_RESULT_FACTORY_H

#include "../../../ResultModel/include/BoundingBox.h"
#include "../../../ResultModel/include/DetectionResult.h"

#include <string>
#include <list>

using namespace std;

class DetectionResultFactory{
    public:
        DetectionResult build(string imageId, string neuralNetworkId, list<BoundingBox> boundingBoxes);
};
#endif