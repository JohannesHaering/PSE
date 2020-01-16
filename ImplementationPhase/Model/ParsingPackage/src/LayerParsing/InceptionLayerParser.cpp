#include "InceptionLayerParser.hpp"
#include "NeuralNetworkParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>

NeuralNetworkLayer InceptionLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation();
    InceptionLayerFactory factory = InceptionLayerFactory();
    factory.setName(LayerParserDistribution::INCEPTION);
    factory.setInputDimensions(inputDimensions);

    auto it = LineBreakParser::splitIntoLines(toParse).begin();
    auto chain = NeuralNetworkParser().parse(toParse.substr((*it).size(), toParse.size()));

    factory.addLayerChain(chain);

    return factory.buildLayer();
}