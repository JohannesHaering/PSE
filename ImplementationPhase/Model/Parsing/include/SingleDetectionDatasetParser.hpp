#ifndef SINGLE_DETECTION_DATASET_PARSER_H_
#define SINGLE_DETECTION_DATASET_PARSER_H_

#include "Parser.hpp"
#include "SingleDetectionDataset.hpp"

#include <string>

class SingleDetectionDatasetParser : public Parser<SingleDetectionDataset> {
    public:
        SingleDetectionDataset parse(std::list<std::string> toParse);
};
#endif