#ifndef TRAINER_DETECTION_DATA_SUPPLY_H_
#define TRAINER_DETECTION_DATA_SUPPLY_H_

#include "DetectionData.hpp"
#include "SingleDetectionDataset.hpp"
#include "DetectionDataFacade.hpp"
#include "TrainerDataSupply.hpp"

#include <string>
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

class TrainerDetectionDataSupply : public TrainerDataSupply
{
public:
    TrainerDetectionDataSupply(std::string directory, int width, int height, int channels);
    std::vector<float> getOutputVector(std::string id) override;

protected:
    void splitData() override;

private:
    DetectionData dataSet;
    DetectionData dataSetTraining;
    DetectionData dataSetTest;
};
#endif