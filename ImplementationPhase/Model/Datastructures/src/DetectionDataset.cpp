#include "DetectionDataset.h"
#include "SingleDetectionDataset.h"

#include <list>

using namespace std;

DetectionDataset::DetectionDataset(list<SingleDetectionDatset> dataset) : dataset(dataset) {}

list<SingleDetectionDataset> getDataset() { return dataset; }