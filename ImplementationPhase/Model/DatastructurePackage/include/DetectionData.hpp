#ifndef DETECTION_DATASET_H
#define DETECTION_DATASET_H

#include "SingleDetectionDataset.hpp"
#include <list>

class DetectionData
{
public:
    DetectionData(std::list<SingleDetectionDataset> dataset);
    std::list<SingleDetectionDataset> getDataset();

private:
    std::list<SingleDetectionDataset> dataset;
};
#endif