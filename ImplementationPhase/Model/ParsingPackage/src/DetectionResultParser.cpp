#include "DetectionResultFactory.hpp"
#include "Parser.hpp"
#include "BoundingBoxParser.hpp"
#include "DetectionResultParser.hpp"
#include "DetectionResult.hpp"

#include <string>
#include <list>
#include <stdexcept>

DetectionResult DetectionResultParser::parse(std::string toParse)
{
    auto parts = Parser::splitBySymbol(toParse, basePartsDelimeter);
    if (parts.size() < 3 || parts.size() > 3)
    {
        throw std::invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto imageId = *iterator;
    ++iterator;
    auto neuralNetworkId = *iterator;
    ++iterator;
    auto boundingBoxes = *iterator;

    std::list<BoundingBox> parsedBoundingBoxes;
    auto boundingBoxParser = BoundingBoxParser();
    auto singleBoundingBoxes = Parser::splitBySymbol(boundingBoxes, boundingBoxDelimeter);
    for (auto boundingBoxIterator = singleBoundingBoxes.begin(); boundingBoxIterator != singleBoundingBoxes.end(); ++boundingBoxIterator)
    {
        parsedBoundingBoxes.push_back(boundingBoxParser.parse(*boundingBoxIterator));
    }

    return DetectionResultFactory().build(imageId, neuralNetworkId, parsedBoundingBoxes);
}
