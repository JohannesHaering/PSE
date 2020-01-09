#include "../include/Image.h"
#include "../include/SingleDetectionDataset.h"
#include "../../ResultModel/include/DetectionResult.h"

SingleDetectionDataset::SingleDetectionDataset(Image image, DetectionResult detectionResult) : image(image), detectionResult(detectionResult) {}
Image SingleDetectionDataset::getImage() { return image; }
DetectionResult SingleDetectionDataset::getDetectionResult() { return detectionResult; }