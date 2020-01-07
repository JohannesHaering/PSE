#include "../include/Parser.h"
#include "../include/ClassProbabilityParser.h"
#include "../include/Factory/ClassProbabilityFactory.h"
#include "../../ResultModel/include/ClassProbability.h"

#include <string>
#include <stdexcept>

using namespace std;

ClassProbability ClassProbabilityParser::parse(string toParse){
    auto parts = Parser::splitBySymbol(toParse, delimeter);
    if(parts.size < 2 || parts.size > 2) {
        throw invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto classId = *iterator;
    ++iterator;
    auto probabilityString = *iterator;
    float probability = ::atof(probabilityString.c_str());

    return ClassProbabilityFactory().build(classId, probability);
}