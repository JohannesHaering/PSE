#include "ClassificationDatasetParser.hpp"
#include "ClassificationResult.hpp"
#include "ClassProbability.hpp"
#include "Parser.hpp"
#include "ClassProbabilityParser.hpp"
#include "ClassificationResultFactory.hpp"

#include <string>
#include <list>

ClassificationResult ClassificationDatasetParser::parse(std::string toParse)
{
    std::list<ClassProbability> parsedProbabilities;
    auto probabilityParser = ClassProbabilityParser();
    auto singleProbabilities = Parser::splitBySymbol(toParse, probabilitiesDelimeter);
    for (auto probabilitiesIterator = singleProbabilities.begin(); probabilitiesIterator != singleProbabilities.end(); ++probabilitiesIterator)
    {
        parsedProbabilities.push_back(probabilityParser.parse(*probabilitiesIterator));
    }

    return ClassificationResultFactory().build("", "", parsedProbabilities);
}
