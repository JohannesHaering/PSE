#include "../include/Factory/DetectionResultFactory.h"
#include "../include/Parser.h"
#include "../include/BoundingBoxParser.h"
#include "../include/DetectionResultParser.h/"
#include "../../ResultModel/include/DetectionResult.h"

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

DetectionResult DetectionResultParser::parse(string toParse){
    auto parts = Parser::splitBySymbol(toParse, basePartsDelimeter);
    if(parts.size() < 3 || parts.size() > 3){
        throw invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto imageId = *iterator;
    ++iterator;
    auto neuralNetworkId = *iterator;
    ++iterator;
    auto boundingBoxes = *iterator;

    list<BoundingBox> parsedBoundingBoxes;
    auto boundingBoxParser = BoundingBoxParser();
    auto singleBoundingBoxes = Parser::splitBySymbol(boundingBoxes, boundingBoxDelimeter);
    for(auto boundingBoxIterator = singleBoundingBoxes.begin(); boundingBoxIterator != singleBoundingBoxes.end(); ++boundingBoxIterator) {
        parsedBoundingBoxes.push_back(boundingBoxParser.parse(*boundingBoxIterator));
    }

    return DetectionResultFactory().build(imageId, neuralNetworkId, parsedBoundingBoxes);
}    