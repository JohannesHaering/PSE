#include "SingleDetectionDataset.hpp"
#include "DetectionResult.hpp"
#include <string>

SingleDetectionDataset::SingleDetectionDataset(std::string imageID, std::string imageLocation, std::list<BoundingBox> boundingBoxes) : imageID(imageID), imageLocation(imageLocation), boundingBoxes(boundingBoxes) {}
std::string SingleDetectionDataset::getImageLocation() { return imageLocation; }
std::list<BoundingBox> SingleDetectionDataset::getBoundingBoxes() { return boundingBoxes; }