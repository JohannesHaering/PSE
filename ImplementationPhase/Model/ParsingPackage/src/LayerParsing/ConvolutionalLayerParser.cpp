#include "ConvolutionalLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionalLayer.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NeuralNetworkLayer ConvolutionalLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    ConvolutionalLayerFactory factory = ConvolutionalLayerFactory();
    factory.setName(LayerParserDistribution::CONVOLUTIONAL);
    factory.setInputDimensions(LayerParser::inputDimensions);

    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts1It != STRIDE)
        throw std::invalid_argument("Wrong Format");
    factory.setStride(::atoi(*(++parts1It)));
    ++it;

    auto parts2It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts2It != PADDING)
        throw std::invalid_argument("Wrong Format");
    factory.setPadding(::atoi(*(++parts2It)));
    ++it;

    auto parts3It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if(*parts3It != WEIGHTS_TENSOR)
        throw std::invalid_argument("Wrong format");

    auto valuePart = *(++parts3It);
    auto tensor = LayerParser::parse3DFloatArray(valuePart);

    factory.setWeightTensors(tensor);

    return factory.buildLayer();
}