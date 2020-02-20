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

NetworkLayer* DenseLayerParser::parse(std::string toParse)
{
	//LayerParser::extractGeneralInformation(toParse);

	DenseLayerFactory factory = DenseLayerFactory();
	//factory.setInputDimensions(LayerParser::inputDimensions);
	//factory.setBatchSize(batchSize);

	std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
	std::list<std::string>::iterator it = lines.begin();
	++it;

	std::list<std::string> val = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER);
	auto parts1It = val.begin();
	if (*parts1It != WEIGHTS_TENSOR)
		throw std::invalid_argument("Wrong format");
	++parts1It;
	factory.setMatrix(LayerParser::parse2DFloatArray(*parts1It));
	++it;

	std::list<std::string> val2 = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER);
	auto parts2It = val2.begin();
	if (*parts2It != BIASES)
		throw std::invalid_argument("Wrong format");
	++parts1It;
	factory.setBiases(LayerParser::parseFloatArray(*parts2It));

	return factory.buildLayer();
}

std::string DenseLayerParser::parseBack(NetworkLayer* layer)
{
	DenseLayer* denselayer = (DenseLayer*)layer;
	std::string output = "";
	//output += saveGeneralInformation(layer);
	output += "[dense]";
	output += WEIGHTS_TENSOR;
	output += LayerParser::VALUE_TYPE_DELIMETER;
	output += LayerParser::save2DFloatArray(denselayer->get_weights());
	output += "\n";
	output += BIASES;
	output += LayerParser::VALUE_TYPE_DELIMETER;
	output += LayerParser::saveFloatArray(denselayer->get_biase());
	output += "\n";

	return output;
}
