#ifndef POWER_PREDICTOR_FROM_FILE_H_
#define POWER_PREDICTOR_FROM_FILE_H_

#include "Predictor.hpp"

class PowerPredictorFromFile : public Predictor
{
public:
    PowerPredictorFromFile();
    std::map<std::string, float> predict(std::list<std::string> deviceIds) override;
};
#endif
