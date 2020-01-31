#ifndef DETECTION_DATASET_PARSER_H_
#define DETECTION_DATASET_PARSER_H_

#include "Parser.hpp"
#include "DetectionData.hpp"
#include "SingleDetectionDatasetParser.hpp"

#include <string>
#include <list>

class DetectionDataParser : public SingleDetectionDatasetParser
{
public:
    DetectionData parse(std::list<std::string> toParse);
};
#endif
