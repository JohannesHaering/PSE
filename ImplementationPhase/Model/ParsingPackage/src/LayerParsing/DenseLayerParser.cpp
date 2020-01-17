#include "DenseLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NeuralNetworkLayer DenseLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    DenseLayerFactory factory = DenseLayerFactory();
    factory.setName(LayerParserDistribution::DENSE);
    factory.setInputDimensions(LayerParser::inputDimensions);

    auto lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER).begin();
    if (*parts1It != WEIGHTS_TENSOR)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory.setMatrix(LayerParser::parse2DFloatArray(*parts1It));

    return factory.buildLayer();
}
