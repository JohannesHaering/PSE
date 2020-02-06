#ifndef CLASSIFICATION_PARSER_H_
#define CLASSIFICATION_PARSER_H_

#include "Parser.hpp"
#include "ClassificationResultFactory.hpp"
#include "ClassificationResult.hpp"

#include <string>
#include <vector>
#include <list>

class ClassificationResultParser : public Parser<ClassificationResult>
{
public:
    ClassificationResult* parse(std::string toParse);
    ClassificationResult* parse(std::string imageId, std::string neuralNetworkId, std::list<std::string> labels, std::vector<float> probabilities);
    std::string parseBack(ClassificationResult classificationResult);

private:
    std::string basePartsDelimeter = "#";
    std::string probabilitiesDelimeter = "/";
};
#endif
