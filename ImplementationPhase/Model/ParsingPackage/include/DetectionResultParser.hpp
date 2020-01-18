#ifndef DETECTION_RESULT_PARSER_H_
#define DETECTION_RESULT_PARSER_H_

#include "Parser.hpp"
#include "DetectionResultFactory.hpp"
#include "DetectionResult.hpp"

#include <string>

class DetectionResultParser : public Parser<DetectionResult>
{
public:
    DetectionResult parse(std::string toParse);
    std::string parseBack(DetectionResult detectionResult);

private:
    std::string basePartsDelimeter = "#";
    std::string boundingBoxDelimeter = "|";
};
#endif