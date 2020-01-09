#include "DetectionData.h"
#include "SingleDetectionDataset.h"

#include <list>

using namespace std;

DetectionData::DetectionDataset(list<SingleDetectionDatset> dataset) : dataset(dataset) {}

list<SingleDetectionData> getDataset() { return dataset; }