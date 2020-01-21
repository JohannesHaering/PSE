#include "LRNLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LRNType.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <stdexcept>

NetworkLayer LRNLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    LocalResponseNormalizationLayerFactory factory = LocalResponseNormalizationLayerFactory();
    factory.setName(LayerParserDistribution().LOCAL_RESPONSE_NORMALIZATION);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER).begin();
    if (*parts1It != DEPTH)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory.setDepth(::atoi((*parts1It).c_str()));

    ++it;
    auto parts2It = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER).begin();
    if (*parts2It != LRN_TYPE)
        throw std::invalid_argument("Wrong format");
    ++parts2It;
    if (*parts2It == "inter")
    {
        factory.setType(LRNType::INTER_CHANNEL);
    }
    else
    {
        factory.setType(LRNType::INTRA_CHANNEL);
    }

    return factory.buildLayer();
}

std::string LRNLayerParser::parseBack(LocalResponseNormalizationLayer layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);
    output += DEPTH;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getDepth());
    output += "\n";
    output += LRN_TYPE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    switch (layer.getType())
    {
    case LRNType::INTER_CHANNEL:
        output += "inter";
        break;
    case LRNType::INTRA_CHANNEL:
        output += "intra";
        break;
    }
    output += "\n";
    return output;
}