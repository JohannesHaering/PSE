#ifndef CLASSIFICATION_PARSER_H
#define CLASSIFICATION_PARSER_H

#include "Parser.h"
#include "Factory/ClassificationResultFactory.h"
#include "../../ResultModel/include/ClassificationResult.h"

#include <string>

using namespace std;

class ClassificationResultParser : public Parser<ClassificationResult>{
    public:
        ClassificationResult parse(string toParse);
    private:
        string basePartsDelimeter = "#";
        string probabilitiesDelimeter = "/";
};
#endif