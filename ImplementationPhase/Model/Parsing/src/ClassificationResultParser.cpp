#include "../include/Parser.h"
#include "../include/ClassificationResultParser.h"
#include "../include/Factory/ClassificationResultFactory.h"
#include "../../ResultModel/include/ClassificationResult.h"
#include "../include/ClassProbabilityParser.h"

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

ClassificationResult ClassificationResultParser::parse(string toParse) {
    auto parts = Parser::splitBySymbol(toParse, basePartsDelimeter);
    if(parts.size() < 3 || parts.size() > 3){
        throw invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto imageId = *iterator;
    ++iterator;
    auto neuralNetworkId = *iterator;
    ++iterator;
    auto probabilities = *iterator;

    list<ClassProbability> parsedProbabilities;
    auto probabilityParser = ClassProbabilityParser();
    auto singleProbabilities = Parser::splitBySymbol(probabilities, probabilitiesDelimeter);
    for(auto probabilitiesIterator = singleProbabilities.begin(); probabilitiesIterator != singleProbabilities.end(); ++probabilitiesIterator) {
        parsedProbabilities.push_back(probabilityParser.parse(*probabilitiesIterator));
    }

    return ClassificationResultFactory().build(imageId, neuralNetworkId, parsedProbabilities);
}