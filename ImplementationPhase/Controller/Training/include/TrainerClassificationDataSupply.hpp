#ifndef TRAINER_CLASSIFICATION_DATA_SUPPLY_H_
#define TRAINER_CLASSIFICATION_DATA_SUPPLY_H_

#include "ClassificationResult.hpp"
#include "ClassificationDatasetFacade.hpp"
#include "TrainerDataSupply.hpp"
#include "DataType.hpp"
#include "ClassificationResult.hpp"
#include "MatrixDefine.hpp"
#include "MNISTDataParser.hpp"


#include <string>
#include <list>
#include <map>
#include <opencv2/opencv.hpp>

class TrainerClassificationDataSupply : public TrainerDataSupply
{
public:
    TrainerClassificationDataSupply(std::string directory, int width, int height, int channels, int batchSize);
    TrainerClassificationDataSupply(DATATYPE type, int batchSize);

    TENSOR(float) getTrainingBatchInput(int numb) override;
    TENSOR(float) getTrainingBatchOutput(int numb) override;
    TENSOR(float) getTestBatchInput(int numb) override;
    TENSOR(float) getTestBatchOutput(int numb) override;

protected:
    MNISTDataParser* mnistDataParser;
};
#endif
