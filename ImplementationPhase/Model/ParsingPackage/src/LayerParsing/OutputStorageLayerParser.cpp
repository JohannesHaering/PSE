#include "OutputStorageLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "OutputStorageLayer.hpp"
#include "OutputStorageLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NeuralNetworkLayer OutputStorageLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    OutputStorageLayerFactory factory = OutputStorageLayerFactory();
    factory.setName(LayerParserDistribution::OUTPUT_STORAGE);
    factory.setInputDimensions(inputDimensions);

    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;

    auto parts1It = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER).begin();
    if(*parts1It != OUTPUT_DATA)
        throw std::invalid_argument("Wrong format");

    auto valuePart = *(++parts1It);
    auto data = LayerParser::parse3DFloatArray(valuePart);

    factory.setData(data);

    return factory.buildLayer();
}