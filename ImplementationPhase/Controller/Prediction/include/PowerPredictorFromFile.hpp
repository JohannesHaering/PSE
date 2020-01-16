#ifndef POWER_PREDICTOR_H_
#define POWER_PREDICTOR_H_

#include <string>
#include <vector>

class PowerPredictorFromFile {

    public:
		PowerPredictorFromFile();
        float predict(std::vector<std::string> ids);

};
#endif