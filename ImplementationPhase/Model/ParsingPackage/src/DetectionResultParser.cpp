#include "DetectionResultFactory.hpp"
#include "Parser.hpp"
#include "BoundingBoxParser.hpp"
#include "DetectionResultParser.hpp"
#include "DetectionResult.hpp"

#include <string>
#include <list>
#include <stdexcept>

// Format:
// imageId # neuralNetworkId# # BoundingBoxes
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

std::string DetectionResultParser::parseBack(DetectionResult detectionResult)
{
    std::string output = "";
    output.append(detectionResult.getImageID());
    output.append(basePartsDelimeter);
    output.append(detectionResult.getNeuralNetworkID());
    output.append(basePartsDelimeter);

    auto boundingBoxes = detectionResult.getBoundingBoxes();
    auto it = boundingBoxes.begin();
    output.append(BoundingBoxParser().parseBack(*it));
    ++it;

    for (; it != boundingBoxes.end(); ++it)
    {
        output.append(boundingBoxDelimeter);
        output.append(BoundingBoxParser().parseBack(*it));
    }

    return output;
}
