#include "DenseLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer DenseLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    DenseLayerFactory factory = DenseLayerFactory();
    factory.setName(LayerParserDistribution().DENSE);
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

std::string DenseLayerParser::parseBack(DenseLayer layer)
{
    std::string output = "";
    output += saveGeneralInformation(layer);
    output += WEIGHTS_TENSOR;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += LayerParser::save2DFloatArray(layer.getMatrix());
    output += "\n";
    return output;
}
