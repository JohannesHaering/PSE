#ifndef CLASSIFICATION_DATASET_PARSER_H_
#define CLASSIFICATION_DATASET_PARSER_H_

#include "Parser.hpp"
#include "ClassificationResult.hpp"

#include <string>

class ClassificationDatasetParser : public Parser<ClassificationResult>
{
public:
    ClassificationResult parse(std::string toParser);

private:
    std::string basePartsDelimeter = "#";
    std::string probabilitiesDelimeter = "/";
};
#endif
