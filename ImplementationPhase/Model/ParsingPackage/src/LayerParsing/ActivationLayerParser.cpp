#include "ActivationLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "ActivationLayerFactory.hpp"
#include "ActivationLayer.hpp"
#include "LayerParserDistribution.hpp"
#include "Parser.hpp"
#include "LineBreakParser.hpp"

#include <string>
#include <stdexcept>

NeuralNetworkLayer ActivationLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    ActivationLayerFactory factory = new ActivationLayerFactory();
    factory.setName(LayerParserDistribution::ACTIVATION);
    factory.setInputDimensions(LayerParser::inputDimensions);

    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    ++it;
    auto valueParts = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER);
    ++it;

    if (*(valueParts.begin()) != USED_FUNCTION)
    {
        throw std::invalid_argument("Wrong format");
    }

    switch (valueParts.end())
    {
    case SIGMOID:
        factory.setActivation(Activation::SIGMOID);
        break;
    case TANH:
        factory.setActivation(Activation::TANH);
        break;
    case RELU:
        factory.setActivation(Activation::RELU);
        break;
    case LEAKING_RELU:
        factory.setActivation(Activation::LEAKING_RELU);
        factory.setAlpha(extractAlpha(it));
        break;
    case PARAMETRIC_RELU:
        factory.setActivation(Activation::PARAMETRIC_RELU);
        factory.setAlpha(extractAlpha(it));
        break;
    case SOFTMAX:
        factory.setActivation(Activation::SOFTMAX);
        break;
    case SWISH:
        factory.setActivation(Activation::SWISH);
        break;
    default:
        factory.setActivation(Activation::SIGMOID);
        break;
    }

    return factory.buildLayer();
}

float ActivationLayerParser::extractAlpha(std::list<std::string>::iterator alphaIterator)
{
    if (alphaIterator == nullptr)
        return STANDARD_ALPHA;

    auto parts = Parser::splitBySymbol(alphaString, VALUE_TYPE_DELIMETER);
    if (*(parts.begin()) != ALPHA)
    {
        return STANDARD_ALPHA;
    }
    else
    {
        return ::atof(*(parts.end()));
    }
}