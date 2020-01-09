#ifndef SINGLE_DETECTION_DATASET_H
#define SINGLE_DETECTION_DATASET_H

#include "DetectionResult.h"
#include <string>

using namespace  std;

class SingleDetectionDataset {
    public:
        SingleDetectionDataset(string imageLocation, DetectionResult detectionResult);
        string getImageLocation();
        DetectionResult getDetectionResult();
    private:
        string imageLocation;
        DetectionResult detectionResult;
};
#endif