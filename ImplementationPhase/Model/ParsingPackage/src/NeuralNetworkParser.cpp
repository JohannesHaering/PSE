#include "NeuralNetworkParser.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"
#include "NeuralNetwork.hpp"
#include "LayerParserDistribution.hpp"
#include "NeuralNetworkFactory.hpp"
#include "NetworkLayer.hpp"

#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>

NeuralNetwork NeuralNetworkParser::parse(std::string toParse)
{
	std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
	auto it = lines.begin();
	auto firtstLine = *it;
	// parse name of neural network
	auto name = removeCharacter(removeCharacter(firtstLine, TYPE_BEGIN), TYPE_END);

	NeuralNetworkFactory factory = NeuralNetworkFactory();
	factory.setName(name);

	++it;

// Extract labels
	std::list<std::string> parts = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER);
	auto partsIt = parts.begin();
	if(*partsIt != LABELS)
		throw std::invalid_argument("Wrong format");
	++it;
	std::list<std::string> labels = Parser::splitBySymbol(*it, VALUE_DELIMETER);
	factory.setLabels(labels);

	std::list<std::string> val = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER);
	auto parts1It = val.begin();
	if (*parts1It != HEIGHT)
		throw std::invalid_argument("Wrong format");
	++parts1It;
	factory.setHeight(std::atoi(parts1It->c_str()));
	++it;

	// parse width of neural network
	val = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER);
	auto parts2It = val.begin();
	if (*parts2It != WIDTH)
		throw std::invalid_argument("Wrong format");
	++parts2It;
	factory.setWidth(std::atoi(parts2It->c_str()));
	++it;

	// parse channels of neural network
	val = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER);
	auto parts3It = val.begin();
	if (*parts3It != CHANNELS)
		throw std::invalid_argument("Wrong format");
	++parts3It;
	factory.setChannels(std::atoi(parts3It->c_str()));

	++it;

	// Here the layer configurations are comming
	std::list<NetworkLayer> layers;
	std::string currentLayerBlock = "";
	// 0 -> adding lines
	int currentState = 0;
	for (; it != lines.end(); ++it)
	{
		if (*it == "")
			continue;

		if (*(*it).begin() == TYPE_BEGIN && currentLayerBlock != "")
		{
			LayerParserDistribution().parse(currentLayerBlock);
			currentLayerBlock = "";
		}

		currentLayerBlock.append(*it);
		currentLayerBlock.append("\n"); // because the line breaks were erased when the string was split
	}

	// Because behind the last layer isnt the opening of a new layer
	if (currentLayerBlock != "")
	{
		LayerParserDistribution().parse(currentLayerBlock);
		currentLayerBlock = "";
	}

	factory.setLayers(layers);

	return factory.buildNeuralNetwork();
}

std::string NeuralNetworkParser::removeCharacter(std::string text, char toErase)
{
	text.erase(std::remove(text.begin(), text.end(), toErase), text.end());
	return text;
}

std::string NeuralNetworkParser::parseBack(NeuralNetwork neuralNetwork)
{
	std::string output = "";
	output += TYPE_BEGIN;
	output += neuralNetwork.getName();
	output += TYPE_END;
	output += "\n";
	output += LABELS;
	output += VALUE_PART_DELIMETER;
	std::list<std::string> labels = neuralNetwork.getLabels();
	auto labelIt = labels.begin();
	output += *labelIt;
	++labelIt;
	for (; labelIt != labels.end(); ++labelIt) {
		output += VALUE_DELIMETER;
		output += *labelIt;
	}
	output += "\n";
	output += HEIGHT;
	output += VALUE_PART_DELIMETER;
	output += std::to_string(neuralNetwork.getHeight());
	output += "\n";
	output += WIDTH;
	output += VALUE_PART_DELIMETER;
	output += std::to_string(neuralNetwork.getWidth());
	output += "\n";
	output += CHANNELS;
	output += VALUE_PART_DELIMETER;
	output += std::to_string(neuralNetwork.getChannels());
	output += "\n";

	auto it = neuralNetwork.getFirstLayer();
	do {
		output += LayerParserDistribution().parseBack(it);
	} while (it != neuralNetwork.getLastLayer());

	return output;
}
