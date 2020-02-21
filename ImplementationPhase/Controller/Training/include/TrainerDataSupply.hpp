#ifndef TRAINER_DATA_SUPPLY_H_
#define TRAINER_DATA_SUPPLY_H_

#include "Result.hpp"
#include "MatrixDefine.hpp"

#include <string>
#include <list>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>

class TrainerDataSupply
{
public:
    virtual TENSOR(float) getTrainingBatchInput(int numb) = 0;
    virtual TENSOR(float) getTrainingBatchOutput(int numb) = 0;
    virtual TENSOR(float) getTestBatchInput(int numb) = 0;
    virtual TENSOR(float) getTestBatchOutput(int numb) = 0;

protected:
    const float TRAINING_PART = 0.7f;
    const float TEST_PART = 0.3f;

    std::vector<TENSOR(float)*> trainingInputBatches;
    std::vector<TENSOR(float)*> testInputBatches;
    std::vector<TENSOR(float)*> trainingOutputBatches;
    std::vector<TENSOR(float)*> testOutputBatches;
    std::vector<TENSOR(float)> allInputBatches;
    std::vector<TENSOR(float)> allOutputBatches;

    std::string extractFileName(std::string path);
};
#endif
