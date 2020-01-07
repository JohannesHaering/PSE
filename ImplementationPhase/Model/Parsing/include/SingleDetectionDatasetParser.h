#ifndef SINGLE_DETECTION_DATASET_PARSER_H
#define SINGLE_DETECTION_DATASET_PARSER_H

#include "Parser.h"
#include "Factory/DetectionDataFactory.h"
#include "../../DataStructures/include/DetectionData.h"

#include <string>

class DetectionDataParser : public Parser<DetectionData> {
    public:
        DetectionData parse(string toParse);
};
#endif