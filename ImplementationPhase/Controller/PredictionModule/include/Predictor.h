#ifndef PREDICTOR_H_
#define PREDICTOR_H_

#include <list>
#include <map>
#include <string>

class Predictor {
    public:
        std::map<std::string, float> predict(std::list<std::string> deviceIds);
        Predictor();
    protected:
        std::string filePath;
        std::list<std::string> loadFile();
        std::map<std::string, float> parseToFloat(std::list<std::string> values);
};

#endif