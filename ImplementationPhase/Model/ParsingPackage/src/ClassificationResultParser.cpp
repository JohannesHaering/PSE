#include "Parser.hpp"
#include "ClassificationResultParser.hpp"
#include "ClassificationResultFactory.hpp"
#include "ClassificationResult.hpp"
#include "ClassProbabilityParser.hpp"

#include <string>
#include <list>
#include <stdexcept>

ClassificationResult ClassificationResultParser::parse(std::string toParse)
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
    auto probabilities = *iterator;

    std::list<ClassProbability> parsedProbabilities;
    auto probabilityParser = ClassProbabilityParser();
    auto singleProbabilities = Parser::splitBySymbol(probabilities, probabilitiesDelimeter);
    for (auto probabilitiesIterator = singleProbabilities.begin(); probabilitiesIterator != singleProbabilities.end(); ++probabilitiesIterator)
    {
        parsedProbabilities.push_back(probabilityParser.parse(*probabilitiesIterator));
    }

    return ClassificationResultFactory().build(imageId, neuralNetworkId, parsedProbabilities);
}