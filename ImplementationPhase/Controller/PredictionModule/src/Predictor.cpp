#include "Predictor.hpp"

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <utility>
#include <map>

std::map<std::string, float> Predictor::predict(std::list<std::string> deviceIDs)
{
    std::list<std::string> lines = loadFile();
    std::map<std::string, float> allPairs = parseToFloat(lines);
    std::map<std::string, float> filterd = filter(allPairs, deviceIDs);

    return filterd;
}

std::list<std::string> Predictor::loadFile()
{
    std::ifstream file(filePath);
    std::string temp;
    std::list<std::string> values;

    // Every line has the format:
    // <deviceId>=<value>
    while (std::getline(file, temp))
    {
        values.std::list<std::string>::push_back(temp);
    }

    file.close();

    return values;
}

std::map<std::string, float> Predictor::parseToFloat(std::list<std::string> values)
{
    std::map<std::string, float> parsed;
    std::string delimiter = "=";
    for (std::list<std::string>::iterator it = values.begin(); it != values.end(); ++it)
    {
        // split the line
        size_t pos = 0;
        std::string deviceId;
        std::string value;
        pos = (*it).find(delimiter);
        deviceId = (*it).substr(0, pos);
        (*it).erase(0, pos + delimiter.length());
        value = (*it);

        // Parse the value
        float floatValue = ::atof(value.c_str());

        // Create Pair
        std::pair<std::string, float> pair = std::pair(deviceId, floatValue);

        // Add to map
        parsed.insert(pair);
    }

    return parsed;
}

std::map<std::string, float> Predictor::filter(std::map<std::string, float> all, std::list<std::string> desired){
    std::map<std::string, float> filtered;
    
    for(std::list<std::string>::iterator it = desired.begin(); it !=desired.end(); ++it){
        filtered.std::map<std::string, float>::insert(*(all.std::map<std::string, float>::find(*it)));
    }

    return filtered;
}