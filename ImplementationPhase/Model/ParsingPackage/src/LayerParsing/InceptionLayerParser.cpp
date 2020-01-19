#include "InceptionLayerParser.hpp"
#include "NeuralNetworkParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>

NetworkLayer InceptionLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);
    InceptionLayerFactory factory = InceptionLayerFactory();
    factory.setName(LayerParserDistribution().INCEPTION);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    auto chain = NeuralNetworkParser().parse(toParse.substr((*it).size(), toParse.size()));

    factory.addLayerChain(chain);

    return factory.buildLayer();
}

std::string InceptionLayerParser::parseBack(InceptionLayer layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);
    output += NeuralNetworkParser().parseBack(layer.getFirstChain());
    return output;
}