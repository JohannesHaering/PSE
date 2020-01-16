#ifndef PERFORMANCE_PREDICTOR_H_
#define PERFORMANCE_PREDICTOR_H_

#include <string>
#include <vector>

class PerformancePredictorFromFile {

    public:
		PerformancePredictorFromFile();
        float predict(std::vector<std::string> ids);

};
#endif