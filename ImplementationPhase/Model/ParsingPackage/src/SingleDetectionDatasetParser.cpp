#include "SingleDetectionDatasetParser.hpp"
#include "BoundingBox.hpp"
#include "BoundingBoxParser.hpp"
#include "LineBreakParser.hpp"
#include "SingleDetectionDataset.hpp"
#include <string>
#include <list>

// Format of the file
// <image_name>
// <image_location>
// <BoundingBox1>
// <BoundingBox2>
// ...
// Format of the bounding box is like the result of a bounding box
// <X>$<Y>$<Width>$<Height>$<ClassProbability1>/<ClassProbability2>/...
// Format of the ClassProbability
// <classId>:<probability>
SingleDetectionDataset SingleDetectionDatasetParser::parse(std::string toParse)
{
    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);  
    auto iterator = lines.begin();
    auto imageID = *iterator;
    ++iterator;
    auto imageLocation = *iterator;
    ++iterator;
    std::list<BoundingBox> boundingBoxes;
    for(; iterator != lines.end(); ++iterator){
        boundingBoxes.push_back(BoundingBoxParser().parse(*iterator));
    }
    
    return SingleDetectionDataset(imageID, imageLocation, boundingBoxes);
}