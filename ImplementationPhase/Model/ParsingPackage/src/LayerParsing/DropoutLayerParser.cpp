#include "DropoutLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DropoutLayer.hpp"
#include "DropoutLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer DropoutLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    DropoutLayerFactory factory = DropoutLayerFactory();
    factory.setName(LayerParserDistribution().DROPOUT);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    ++it;
    auto parts1It = Parser::splitBySymbol(*it, LayerParser::VALUE_PARTS_DELIMETER).begin();
    if (*parts1It != DROPOUT_RATE)
    {
        factory.setDropoutRate(STANDARD_RATE);
    }
    else
    {
        ++parts1It;
        factory.setDropoutRate(std::stof((*parts1It).c_str()));
    }

    return factory.buildLayer();
}

std::string DropoutLayerParser::parseBack(DropoutLayer layer)
{
    std::string output = "";
    output += saveGeneralInformation(layer);
    output += DROPOUT_RATE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getDropoutRate());
    output += "\n";
    return output;
}