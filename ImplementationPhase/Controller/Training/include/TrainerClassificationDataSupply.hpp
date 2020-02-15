#ifndef TRAINER_CLASSIFICATION_DATA_SUPPLY_H_
#define TRAINER_CLASSIFICATION_DATA_SUPPLY_H_

#include "ClassificationResult.hpp"
#include "ClassificationDatasetFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "DataType.hpp"
#include "ClassificationResult.hpp"
#include "MatrixDefine.hpp"

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
    std::vector<float> createOutputVector(ClassificationResult result);
    MatrixDefine::Tensor(float) getTrainingBatchInput(int batchSize, int numb) override;
    MatrixDefine::Tensor(float) getTrainingBatchOutput(int batchSize, int numb) override;

    int getAmountClasses();

protected:
    void splitData() override;

private:
    ClassificationResult createResult(int i, std::vector<float> label);

    std::vector<ClassificationResult> dataSet;
    std::vector<ClassificationResult*> dataSetTraining;
    std::vector<ClassificationResult*> dataSetTest;
    std::map<std::string, ClassificationResult*> dataMap;
    std::vector<std::string> classnames;
};
#endif