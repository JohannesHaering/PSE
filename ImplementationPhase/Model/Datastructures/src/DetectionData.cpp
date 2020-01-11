#include "DetectionData.hpp"
#include "SingleDetectionDataset.hpp"

#include <list>

DetectionData::DetectionData(std::list<SingleDetectionDataset> dataset) : dataset(dataset) {}

std::list<SingleDetectionDataset> DetectionData::getDataset() { return dataset; }