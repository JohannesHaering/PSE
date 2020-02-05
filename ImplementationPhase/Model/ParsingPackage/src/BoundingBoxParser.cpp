#include "BoundingBoxParser.hpp"
#include "BoundingBoxFactory.hpp"
#include "Parser.hpp"
#include "ClassProbabilityParser.hpp"
#include "BoundingBox.hpp"

#include <string>
#include <list>
#include <stdexcept>

// Format of the string
// <X>$<Y>$<Width>$<Height>$<ClassProbability1>/<ClassProbability2>/...
// Format of the ClassProbability
// <classId>:<probability>
BoundingBox BoundingBoxParser::parse(std::string toParse)
{
    auto parts = Parser::splitBySymbol(toParse, basePartsDelimeter);
    if (parts.size() < 5 || parts.size() > 5)
    {
        throw std::invalid_argument("Too much parts");
    }
    auto iterator = parts.begin();
    auto x = *iterator;
    ++iterator;
    auto y = *iterator;
    ++iterator;
    auto width = *iterator;
    ++iterator;
    auto height = *iterator;
    ++iterator;
    auto probabilities = *iterator;

    float xf = std::stof(x.c_str());
    float yf = std::stof(y.c_str());
    float widthf = std::stof(width.c_str());
    float heightf = std::stof(height.c_str());

    std::list<ClassProbability> parsedProbabilities;
    auto probabilityParser = ClassProbabilityParser();
    auto singleProbabilities = Parser::splitBySymbol(probabilities, probabilitiesDelimeter);
    for (auto probabilitiesIterator = singleProbabilities.begin(); probabilitiesIterator != singleProbabilities.end(); ++probabilitiesIterator)
    {
        parsedProbabilities.push_back(probabilityParser.parse(*probabilitiesIterator));
    }

    return BoundingBoxFactory().build(xf, yf, widthf, heightf, parsedProbabilities);
}

std::string BoundingBoxParser::parseBack(BoundingBox boundingBox)
{
    std::string output = "";
    output.append(std::to_string(boundingBox.getX()));
    output.append(basePartsDelimeter);
    output.append(std::to_string(boundingBox.getY()));
    output.append(basePartsDelimeter);
    output.append(std::to_string(boundingBox.getWidth()));
    output.append(basePartsDelimeter);
    output.append(std::to_string(boundingBox.getHeight()));
    output.append(basePartsDelimeter);

    auto probabilities = boundingBox.getProbabilities();
    auto it = probabilities.begin();
    output.append(ClassProbabilityParser().parseBack(*it));
    ++it;

    for (; it != probabilities.end(); ++it)
    {
        output.append(probabilitiesDelimeter);
        output.append(ClassProbabilityParser().parseBack(*it));
    }

    return output;
}