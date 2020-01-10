#ifndef CURRENT_PERFORMANCE_PREDICTOR_H_
#define CURRENT_PERFORMANCE_PREDICTOR_H_

#include "PerformancePredictorFromFile.hpp"
#include <string>
#include <map>

class CurrentPerformancePredictor : public PerformancePredictorFromFile
{
public:
    std::map<std::string, float> predict(std::list<std::string> deviceIds) override;
private:
    void save(std::map<std::string, float> values);
    std::string nerualNetworkPath = "..\\Data\\test_neuralnetwork.cfg";
    std::string imagePath = "..\\Data\\test_image.jpeg";
};
#endif