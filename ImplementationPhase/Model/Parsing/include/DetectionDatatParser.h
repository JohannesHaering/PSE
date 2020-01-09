#ifndef DETECTION_DATASET_PARSER
#define DETECTION_DATASET_PARSER

#include "LineBreakParser.h"
#include "SingleDetectionDatasetParser.h"
#include "DetectionData.h"

#include <string>
#include <list>

using namespace std;

class DetectionDatasetParser : public LineBreakParser<DetectionData>{
    public:
        list<DetectionData> parse(string toParse);
};
#endif