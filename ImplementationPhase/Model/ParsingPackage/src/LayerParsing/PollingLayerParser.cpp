#include "PollingLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "PollingLayer.hpp"
#include "PoolingLayerFactory.hpp"
#include "PollingType.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <stdexcept>

NeuralNetworkLayer PollingLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    PollingLayerFactory factory = PollingLayerFactory();
    factory.setName(LayerParserDistribution::POLLING);
    factory.setInputDimensions(inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    ++it;

    auto parts1It = (*it).splitBySymbol(VALUE_TYPE_DELIMETER).begin();
    if(*parts1It != SIZE)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory.setSize(::atoi(*parts1It));
    ++it;

    auto parts2It = (*it).splitBySymbol(VALUE_TYPE_DELIMETER).begin();
    if(*parts2It != STRIDE)
        throw std::invalid_argument("Wrong format");
    ++parts2It;
    factory.setStride(::atoi(*parts2It));
    ++it;

    auto parts3It = (*it).splitBySymbol(VALUE_TYPE_DELIMETER).begin();
    if(*parts3It != POLLING_TYPE)
        throw std::invalid_argument("Wrong format");
    ++parts3It;

    if(*parts3It == "average"){
        factory.setType(PollingType::AVERAGE);
    } else{
        factory.setType(PollingType::MAX);
    }

    return factory.buildLayer();
}
