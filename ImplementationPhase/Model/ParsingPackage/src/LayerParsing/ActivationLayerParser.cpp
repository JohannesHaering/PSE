#include "ActivationLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ActivationLayerFactory.hpp"
#include "ActivationLayer.hpp"
#include "LayerParserDistribution.hpp"
#include "Activation.hpp"
#include "Parser.hpp"
#include "LineBreakParser.hpp"

#include <string>
#include <stdexcept>

NetworkLayer* ActivationLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    ActivationLayerFactory factory = ActivationLayerFactory();
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

    std::string switcher = *(--valueParts.end());
    if (switcher == SIGMOID)
    {
        factory.setActivation(Activation::SIGMOID);
    }
    else if (switcher == TANH)
    {
        factory.setActivation(Activation::TANH);
    }
    else if (switcher == RELU)
    {
        factory.setActivation(Activation::RELU);
    }
    else if (switcher == LEAKING_RELU)
    {
        factory.setActivation(Activation::LEAKING_RELU);
        factory.setAlpha(extractAlpha(*it));
    }
    else if (switcher == PARAMETRIC_RELU)
    {
        factory.setActivation(Activation::PARAMETRIC_RELU);
        factory.setAlpha(extractAlpha(*it));
    }
    else if (switcher == SOFTMAX)
    {
        factory.setActivation(Activation::SOFTMAX);
    }
    else if (switcher == SWISH)
    {
        factory.setActivation(Activation::SWISH);
    }
    else
    {
        factory.setActivation(Activation::SIGMOID);
    }

    return factory.buildLayer();
}

float ActivationLayerParser::extractAlpha(std::string alphaString)
{
    if (alphaString == "")
        return STANDARD_ALPHA;

    auto parts = Parser::splitBySymbol(alphaString, VALUE_TYPE_DELIMETER);
    if (*(parts.begin()) != ALPHA)
    {
        return STANDARD_ALPHA;
    }
    else
    {
        return std::stof((*(--parts.end())).c_str());
    }
}

std::string ActivationLayerParser::parseBack(ActivationLayer* layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);
    output += USED_FUNCTION;
    output += LayerParser::VALUE_TYPE_DELIMETER;

    switch (layer->getActivationType())
    {
    case Activation::SIGMOID:
        output += SIGMOID;
        output += "\n";
        break;
    case Activation::TANH:
        output += TANH;
        output += "\n";
        break;
    case Activation::RELU:
        output += RELU;
        output += "\n";
        break;
    case Activation::LEAKING_RELU:
        output += LEAKING_RELU;
        output += "\n";
        output += saveAlpha(0.01f);
        break;
    case Activation::PARAMETRIC_RELU:
        output += PARAMETRIC_RELU;
        output += "\n";
        output += saveAlpha(0.01f);
        break;
    case Activation::SOFTMAX:
        output += SOFTMAX;
        output += "\n";
        break;
    case Activation::SWISH:
        output += SWISH;
        output += "\n";
        break;
    }

    return output;
}

std::string ActivationLayerParser::saveAlpha(float alpha)
{
    std::string output = "";
    output += ALPHA;
    output += LayerParser::VALUE_TYPE_DELIMETER;
    output += std::to_string(alpha);
    output += "\n";
    return output;
}