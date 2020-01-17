#include "DropoutLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "DropoutLayer.hpp"
#include "DropoutLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NeuralNetworkLayer DropoutLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    DropoutLayerFactory factory = DropoutLayerFactory();
    factory.setName(LayerParserDistribution::DROPOUT);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse);
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, LayerParser::VALUE_PARTS_DELIMETER).begin();
    if(*parts1It != DROPOUT_RATE){
        factory.setDropoutRate(STANDARD_RATE);
    } else{
        ++parts1It;
        factory.setDropoutRate(::atof(**parts1It));
    }
    
    return factory.buildLayer();
}