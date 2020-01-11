#ifndef DETECTION_DATASET_PARSER_H_
#define DETECTION_DATASET_PARSER_H_

#include "LineBreakParser.hpp"
#include "DetectionData.hpp"

#include <string>
#include <list>

class DetectionDataParser : public LineBreakParser<DetectionData>
{
public:
    DetectionData parse(std::list<std::list<std::string>> toParse);
};
#endif