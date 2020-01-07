#include "../include/BoundingBoxParser.h"
#include "../include/Factory/BoundingBoxFactory.h"
#include "../include/Parser.h"
#include "../include/ClassProbabilityParser.h"
#include "../../ResultModel/include/BoundingBox.h"

#include <string>
#include <list>
#include <stdexcept>

using namespace std;

BoundingBox BoundingBoxParser::parse(string toParse) {
    auto parts = Parser::splitBySymbol(toParse, basePartsDelimeter);
    if(parts.size() < 5 || parts.size() > 5){
        throw invalid_argument("Too much parts");
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

    float xf = ::atof(x.c_str());
    float yf = ::atof(y.c_str());
    float widthf = ::atof(width.c_str());
    float heightf = ::atof(height.c_str());

    list<ClassProbability> parsedProbabilities;
    auto probabilityParser = ClassProbabilityParser();
    auto singleProbabilities = Parser::splitBySymbol(probabilities, probabilitiesDelimeter);
    for(auto probabilitiesIterator = singleProbabilities.begin(); probabilitiesIterator != singleProbabilities.end(); ++probabilitiesIterator) {
        parsedProbabilities.push_back(probabilityParser.parse(*probabilitiesIterator));
    }

    return BoundingBoxFactory().build(xf, yf, widthf, heightf, parsedProbabilities);
}