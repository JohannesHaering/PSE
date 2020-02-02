#include "Parser.hpp"
#include "ClassProbabilityParser.hpp"
#include "ClassProbabilityFactory.hpp"
#include "ClassProbability.hpp"

#include <string>
#include <stdexcept>

// Format of the string
// <classId>:<probability>
ClassProbability ClassProbabilityParser::parse(std::string toParse)
{
    auto parts = Parser::splitBySymbol(toParse, delimeter);
    if (parts.size() < 2 || parts.size() > 2)
    {
        throw std::invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto classId = *iterator;
    ++iterator;
    auto probabilityString = *iterator;
    float probability = std::stof(probabilityString.c_str());

    return ClassProbabilityFactory().build(classId, probability);
}

std::string ClassProbabilityParser::parseBack(ClassProbability classProbability)
{
    std::string output = "";
    output += (classProbability.getClassName());
	output += (delimeter);
	output += (std::to_string(classProbability.getProbability()));
    return output;
}