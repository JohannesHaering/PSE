#ifndef SINGLE_DETECTION_DATASET_H
#define SINGLE_DETECTION_DATASET_H

#include "BoundingBox.hpp"
#include <string>
#include <list>

class SingleDetectionDataset
{
public:
    SingleDetectionDataset(std::string imageID, std::string imageLocation, std::list<BoundingBox> boundingBoxes);
    std::string getImageLocation();
    std::list<BoundingBox> getBoundingBoxes();

private:
std::string imageID;
    std::string imageLocation;
    std::list<BoundingBox> boundingBoxes;
};
#endif