#ifndef SINGLE_DETECTION_DATASET_PARSER_H_
#define SINGLE_DETECTION_DATASET_PARSER_H_

#include "LineBreakParser.hpp"
#include "SingleDetectionDataset.hpp"

#include <string>

class SingleDetectionDatasetParser : public LineBreakParser<SingleDetectionDataset> {
    public:
        SingleDetectionDataset parse(std::string toParse) override;
};
#endif
