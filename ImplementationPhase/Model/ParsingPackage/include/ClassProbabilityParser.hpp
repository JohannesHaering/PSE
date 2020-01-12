#ifndef CLASS_PROBABILITY_PARSER_H_
#define CLASS_PROBABILITY_PARSER_H_

#include "Parser.hpp"
#include "ClassProbabilityFactory.hpp"
#include "ClassProbability.hpp"

#include <string>

class ClassProbabilityParser : public Parser<ClassProbability>
{
public:
    ClassProbability parse(std::string toParse);

private:
    std::string delimeter = ":";
};
#endif