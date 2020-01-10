#ifndef PREDICTOR_H_
#define PREDICTOR_H_

#include <list>
#include <map>
#include <string>

class Predictor
{
public:
    std::map<std::string, float> predict(std::list<std::string> deviceIds);

protected:
    std::string filePath;

private:
    std::list<std::string> loadFile();
    std::map<std::string, float> parseToFloat(std::list<std::string> values);
    std::map<std::string, float> filter(std::map<std::string, float> all, std::list<std::string> desired);
};

#endif