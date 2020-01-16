#include "LRNLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LRNType.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <stdexcept>

NeuralNetworkLayer LRNLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    LocalResponseNormalizationLayerFactory factory = LocalResponseNormalizationLayerFactory();
    factory.setName(LayerParserDistribution::LOCAL_RESPONSE_NORMALIZATION);
    factory.setInputDimensions(inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER).begin();
    if(*parts1It != DEPTH)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory(::atoi(*parts1It));

    ++it;
    auto parts2It = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER).begin();
    if(*parts2It != LRN_TYPE)
        throw std::invalid_argument("Wrong format");
    ++parts2It;
    if(*parts2It == "inter"){
        factory.setType(LRNType::INTER_CHANNEL);
    } else{
        factory.setType(LRN_TYPE::INTRA_CHANNEL);
    }

    return factory.buildLayer();    
}
