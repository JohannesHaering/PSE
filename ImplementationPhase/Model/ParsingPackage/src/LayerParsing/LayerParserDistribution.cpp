#include "LineBreakParser.hpp"
#include "LayerParserDistribution.hpp"
#include "DenseLayerParser.hpp"

#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DenseLayer.hpp"
#include "ReLuLayer.hpp"
#include "LeakyReLuLayer.hpp"
#include "SigmoidLayer.hpp"
#include "SoftmaxLayer.hpp"
#include "ActivationLayerParser.hpp"

#include <string>
#include <stdexcept>
#include <algorithm>

NetworkLayer* LayerParserDistribution::parse(std::string toParse)
{
	std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
	auto firstLine = *(lines.begin());
	firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_BEGIN), firstLine.end());
	firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), TYPE_END), firstLine.end());

	std::string extras = "[\n]";
	// Remove first line
	toParse = toParse.substr(firstLine.size() + extras.size(), toParse.size());

	if (firstLine.compare(DENSE) == 0)
	{
		return parseDenseLayer(toParse);
	}
	else if (firstLine.compare(SIGMOID) == 0) {
		return new SigmoidLayer();
	}
	else if (firstLine.compare(SOFTMAX) == 0) {
		return new SoftmaxLayer();
	}
	else if (firstLine.compare(RELU) == 0) {
		return new ReLuLayer();
	}
	else if (firstLine.compare(LEAKYRELU) == 0) {
		return new LeakyReLuLayer();
	}
	else
	{
		throw std::invalid_argument("Wrong format");
	}
}

std::string LayerParserDistribution::parseBack(NetworkLayer* layer)
{
	std::string output = "";
	switch (layer->getLayerType())
	{
	case LayerType::DENSE:
		output += DenseLayerParser().parseBack(layer);
		break;
	case LayerType::LEAKYRELU:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::RELU:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::SOFTMAX:
		output += ActivationLayerParser().parseBack(layer);
		break;
	case LayerType::SIGMOID:
		output += ActivationLayerParser().parseBack(layer);
		break;
	}
	return output;
}

NetworkLayer* LayerParserDistribution::parseDenseLayer(std::string toParse)
{
	return DenseLayerParser().parse(toParse);
}