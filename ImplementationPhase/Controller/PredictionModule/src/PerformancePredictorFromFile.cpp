#include "PerformancePredictorFromFile.hpp"

PerformancePredictorFromFile::PerformancePredictorFromFile(){
    filePath = "../Data/PerformanceData.txt";
}

std::map<std::string, float> PerformancePredictorFromFile::predict(std::list<std::string> deviceIds) {
    std::map<std::string, float> list;
    list.insert({"CPU", 10});
    return list;
}
