#ifndef TRAINER_CLASSIFICATION_DATA_SUPPLY_H_
#define TRAINER_CLASSIFICATION_DATA_SUPPLY_H_

#include "ClassificationResult.hpp"
#include "ClassificationDatasetFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "DataType.hpp"
#include "ClassificationResult.hpp"

#include <string>
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

class TrainerClassificationDataSupply : public TrainerDataSupply
{
public:
    TrainerClassificationDataSupply(std::string directory, int width, int height, int channels);
    TrainerClassificationDataSupply(DATATYPE type);

    std::vector<float> getOutputVector(std::string id) override;
    std::vector<float> createOutputVector(Result result) override;
    int getAmountClasses();

protected:
    void splitData() override;

private:
    ClassificationResult createResult(int i, std::vector<float> label);

    std::list<ClassificationResult> dataSet;
    std::list<ClassificationResult*> dataSetTraining;
    std::list<ClassificationResult*> dataSetTest;
    std::map<std::string, cv::Mat> images;
    std::map<std::string, ClassificationResult*> dataMap;
    std::list<std::string> classnames;
};
#endif