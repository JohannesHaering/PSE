#ifndef CLASS_PROBABILITY_PARSER_H
#define CLASS_PROBABILITY_PARSER_H

#include "Parser.h"
#include "Factory/ClassProbabilityFactory.h"
#include "../../ResultModel/include/ClassProbability.h"

#include <string>

using namespace std;

class ClassProbabilityParser : public Parser<ClassProbability>{
    public:
        ClassProbability parse(string toParse);
    private:
        string delimeter = ":";
};
#endif