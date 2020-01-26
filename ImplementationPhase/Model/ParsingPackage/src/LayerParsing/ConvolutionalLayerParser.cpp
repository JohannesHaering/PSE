#include "ConvolutionalLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionLayer.hpp"
#include "ConvolutionalLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer ConvolutionalLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    ConvolutionalLayerFactory factory = ConvolutionalLayerFactory();
    factory.setName(LayerParserDistribution().CONVOLUTIONAL);
    factory.setInputDimensions(LayerParser::inputDimensions);

    std::list<std::string> lines = LineBreakParser<NetworkLayer>::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts1It != STRIDE)
        throw std::invalid_argument("Wrong Format");
    factory.setStride(::atoi((*(++parts1It)).c_str()));
    ++it;

    auto parts2It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if (*parts2It != PADDING)
        throw std::invalid_argument("Wrong Format");
    factory.setPadding(::atoi((*(++parts2It)).c_str()));
    ++it;

    auto parts3It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if(*parts3It != WEIGHTS_TENSOR)
        throw std::invalid_argument("Wrong format");

    auto valuePart = *(++parts3It);
    auto tensor = LayerParser::parse4DFloatArray(valuePart);

    factory.setWeightTensors(tensor);

    return factory.buildLayer();
}

std::string ConvolutionalLayerParser::parseBack(ConvolutionLayer layer){
    std::string output = "";
    output += saveGeneralInformation(layer);
    output += STRIDE;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getStride());
    output += "\n";
    output += PADDING;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(layer.getPadding());
    output += "\n";
    output += WEIGHTS_TENSOR;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += LayerParser::save4DFloatArray(layer.getWeightsTensor());
    output += "\n";
	return output;
}
