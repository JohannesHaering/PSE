#ifndef CURRENT_PERFORMANCE_PREDICTOR_H_
#define CURRENT_PERFORMANCE_PREDICTOR_H_

#include "PerformancePredictorFromFile.hpp"
#include "Channel.hpp"
#include "NeuralNetworkdAdapter.hpp"

#include <opencv2/opencv.hpp>
#include <list>
#include <string>
#include <map>

class CurrentPerformancePredictor : public PerformancePredictorFromFile
{
public:
    std::map<std::string, float> predict(std::list<std::string> deviceIds) override;
private:
    void save(std::map<std::string, float> values);
    float measureTime(Channel channel, std::list<NeuralNetworkAdapter> neuralNetworks, std::list<cv::Mat> images);
    std::string nerualNetworkPath = "..\\Data\\test_neuralnetwork.cfg";
    std::string imagePath = "..\\Data\\test_image.jpeg";
};
#endif