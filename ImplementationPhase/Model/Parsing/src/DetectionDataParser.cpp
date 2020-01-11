#include "DetectionDataParser.hpp"
#include "SingleDetectionDatasetParser.hpp"
#include "DetectionData.hpp"
#include "SingleDetectionDataset.hpp"

#include <list>
#include <string>

// You get the input of multiple files
// The input of every file has the format of a SingleDetectionDataset
DetectionData DetectionDataParser::parse(std::list<std::list<std::string>> toParse)
{
    std::list<SingleDetectionDataset> datasets;
    for (auto iterator = toParse.begin(); iterator != toParse.end(); ++iterator)
    {
        datasets.push_back(SingleDetectionDatasetParser().parse(*iterator));
    }
    return DetectionData(datasets);
}