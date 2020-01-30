#include "PowerPredictorFromFile.hpp"

PowerPredictorFromFile::PowerPredictorFromFile(){
    filePath = "../Data/PowerData.txt";
}

std::map<std::string, float> PowerPredictorFromFile::predict(std::list<std::string> deviceIds) {
    std::map<std::string, float>* list = new std::map<std::string, float>();
    list->insert({"CPU", 42});
    return *list;
}
