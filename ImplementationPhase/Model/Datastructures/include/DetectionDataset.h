#ifndef DETECTION_DATASET_H
#define DETECTION_DATASET_H

#include "SingleDetectionDataset.h"
#include <list>

using namespace std;

class DetectionDataset {
    public:
        DetectionDataset(list<SingleDetectionDataset> dataset);
        list<SingleDetectionDataset> getDataset();
    private:
        list<SingleDetectionDataset> dataset;
};
#endif