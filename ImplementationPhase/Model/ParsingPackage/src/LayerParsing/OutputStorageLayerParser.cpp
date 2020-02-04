#include "OutputStorageLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "OutputStorageLayer.hpp"
#include "OutputStorageLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer OutputStorageLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    OutputStorageLayerFactory factory = OutputStorageLayerFactory();
    factory.setName(LayerParserDistribution().OUTPUT_STORAGE);
    factory.setInputDimensions(LayerParser::inputDimensions);

    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;

	std::list<std::string> val = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER);
    auto parts1It = val.begin();
    if (*parts1It != OUTPUT_DATA)
        throw std::invalid_argument("Wrong format");

    auto valuePart = *(++parts1It);
    std::vector<std::vector<std::vector<float>>> data = LayerParser::parse3DFloatArray(valuePart);

    factory.setData(data);

    return factory.buildLayer();
}

std::string OutputStorageLayerParser::parseBack(OutputStorageLayer layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);
    output += OUTPUT_DATA;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += save3DFloatArray(layer.getData());
    output += "\n";
	return output;
}