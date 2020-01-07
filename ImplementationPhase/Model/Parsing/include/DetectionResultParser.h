#ifndef DETECTION_RESULT_PARSER_H
#define DETECTION_RESULT_PARSER_H

#include "Parser.h"
#include "Factory/DetectionResultFactory.h"
#include "../../ResultModel/include/DetectionResult.h"

#include <string>

using namespace std;

class DetectionResultParser : public Parser<DetectionResult> {
    public:
        DetectionResult parse(string toParse);
    private:
        string basePartsDelimeter = "#";
        string boundingBoxDelimeter = "|";
};
#endif