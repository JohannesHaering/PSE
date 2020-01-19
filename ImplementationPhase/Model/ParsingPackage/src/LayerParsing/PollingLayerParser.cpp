#include "PollingLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "PollingLayer.hpp"
#include "PollingLayerFactory.hpp"
#include "PollingType.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <stdexcept>

NetworkLayer PollingLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    PollingLayerFactory factory = PollingLayerFactory();
    factory.setName(LayerParserDistribution().POLLING);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts1It != SIZE)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory.setSize(::atoi((*parts1It).c_str()));
    ++it;

    auto parts2It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts2It != STRIDE)
        throw std::invalid_argument("Wrong format");
    ++parts2It;
    factory.setStride(::atoi((*parts2It).c_str()));
    ++it;

    auto parts3It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts3It != POLLING_TYPE)
        throw std::invalid_argument("Wrong format");
    ++parts3It;

    if (*parts3It == "average")
    {
        factory.setType(PollingType::AVEREAGE);
    }
    else
    {
        factory.setType(PollingType::MAX);
    }

    return factory.buildLayer();
}

std::string PollingLayerParser::parseBack(PollingLayer layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);
    output += SIZE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getSize());
    output += "\n";
    output += STRIDE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getStride());
    output += "\n";
    output += POLLING_TYPE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    switch (layer.getType())
    {
    case PollingType::MAX:
        output += "max";
        break;
    case PollingType::AVEREAGE:
        output += "average";
        break;
    }
    output += "\n";
	return output;
}
