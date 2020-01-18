#ifndef DETECTION_DATA_FACADE_h_
#define DETECTION_DATA_FACADE_h_

#include "ModelFacade.hpp"
#include "DetectionData.hpp"

class DetectionDataFacade : public ModelFacade
{
public:
    DetectionData loadDetectionData(std::string directory);
};
#endif