#ifndef CLASSIFICATION_PARSER_H_
#define CLASSIFICATION_PARSER_H_

#include "Parser.hpp"
#include "ClassificationResultFactory.hpp"
#include "ClassificationResult.hpp"

#include <string>

class ClassificationResultParser : public Parser<ClassificationResult>
{
public:
    ClassificationResult parse(std::string toParse);
    std::string parseBack(ClassificationResult classificationResult);

private:
    std::string basePartsDelimeter = "#";
    std::string probabilitiesDelimeter = "/";
};
#endif