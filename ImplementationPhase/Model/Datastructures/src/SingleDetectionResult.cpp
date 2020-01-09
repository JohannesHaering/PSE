#include "../include/Image.h"
#include "../include/SingleDetectionDataset.h"
#include "../../ResultModel/include/DetectionResult.h"
#include <string>

using namespace std;

SingleDetectionDataset::SingleDetectionDataset(string imageLocation, DetectionResult detectionResult) : image(image), detectionResult(detectionResult) {}
string SingleDetectionDataset::getImageLocation() { return imageLocation; }
DetectionResult SingleDetectionDataset::getDetectionResult() { return detectionResult; }