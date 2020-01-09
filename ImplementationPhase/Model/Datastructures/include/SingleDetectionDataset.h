#ifndef SINGLE_DETECTION_DATASET_H
#define SINGLE_DETECTION_DATASET_H

#include "../../ResultModel/include/DetectionResult.h"
#include "Image.h"

class SingleDetectionDataset {
    public:
        SingleDetectionDataset(Image image, DetectionResult detectionResult);
        Image getImage();
        DetectionResult getDetectionResult();
    private:
        Image image;
        DetectionResult detectionResult;
};

#endif