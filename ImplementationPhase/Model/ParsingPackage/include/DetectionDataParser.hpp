#ifndef DETECTION_DATASET_PARSER_H_
#define DETECTION_DATASET_PARSER_H_

#include "Parser.hpp"
#include "DetectionData.hpp"

#include <string>
#include <list>

class DetectionDataParser : public Parser<DetectionData>
{
public:
    DetectionData parse(std::list<std::string> toParse);
};
#endif