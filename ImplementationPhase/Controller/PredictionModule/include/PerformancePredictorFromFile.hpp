#ifndef PERFORMANCE_PREDICTOR_FROM_FILE_H_
#define PERFORMANCE_PREDICTOR_FROM_FILE_H_

#include "Predictor.hpp"

class PerformancePredictorFromFile : public Predictor
{
public:
    PerformancePredictorFromFile();
    std::map<std::string, float> predict(std::list<std::string> deviceIds) override;
};
#endif
