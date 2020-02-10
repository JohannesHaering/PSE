#include "CollectResultsLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "CollectResultsLayerFactory.hpp"
#include "CollectResultsLayer.hpp"
#include "LayerParserDistribution.hpp"

#include <string>

NetworkLayer CollectResultsLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    return CollectResultsLayerFactory().setName(LayerParserDistribution().COLLECT_RESULTS)->setInputDimensions(LayerParser::inputDimensions)->buildLayer();
}

std::string CollectResultsLayerParser::parseBack(CollectResultsLayer layer)
{
    std::string output = "";
    output += saveGeneralInformation(layer);
    return output;
}
