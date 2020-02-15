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
    TrainerDataSupply(std::string directory, int width, int height, int channels);

	std::list<std::string> getDataIds();
    cv::Mat getImage(std::string id);
    virtual std::vector<float> getOutputVector(std::string id) = 0;
    int getSize();
    virtual int getAmountClasses() = 0;
    virtual MatrixDefine::TENSOR(float) getTrainingBatch(int batchSize, int numb) = 0;

protected:
    virtual void splitData() = 0;

    const float TRAINING_PART = 0.7f;
    const float TEST_PART = 0.3f;

    std::map<std::string, cv::Mat> images;
    std::vector<std::string> ids;
    std::list<std::string> labelnames;

private:
    std::string extractFileName(std::string path);
};
#endif
