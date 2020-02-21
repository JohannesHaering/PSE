#include "ActivationLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ActivationLayerFactory.hpp"
#include "ActivationLayer.hpp"
#include "LayerParserDistribution.hpp"
#include "Parser.hpp"
#include "LineBreakParser.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

NetworkLayer* ActivationLayerParser::parse(std::string toParse){
    //LayerParser::extractGeneralInformation(toParse);
    ActivationLayerFactory factory = ActivationLayerFactory();
    //factory.setInputDimensions(LayerParser::inputDimensions);

    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    auto valueParts = Parser::splitBySymbol(*it, LayerParser::VALUE_TYPE_DELIMETER);
    if (*(valueParts.begin()) != USED_FUNCTION)
    {
        throw std::invalid_argument("Wrong format");
    }
    std::string switcher = *(--valueParts.end());
    if (switcher == SIGMOID)
    {
        factory.setActivation(LayerType::SIGMOID);
    }
    else if (switcher == RELU)
    {
        factory.setActivation(LayerType::RELU);
    }
    else if (switcher == LEAKING_RELU)
    {
        factory.setActivation(LayerType::LEAKYRELU);
    }
    else if (switcher == SOFTMAX)
    {
        factory.setActivation(LayerType::SOFTMAX);
    }
    else
    {
        factory.setActivation(LayerType::SIGMOID);
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

std::string ActivationLayerParser::parseBack(NetworkLayer* layer)
{
    std::string output = "[activation]\n";
    //output += LayerParser::saveGeneralInformation(layer);

    output += USED_FUNCTION;
    output += LayerParser::VALUE_TYPE_DELIMETER;

    switch (layer->getLayerType())
    {
    case LayerType::SIGMOID:
        output += SIGMOID;
        output += "\n";
        break;
    case LayerType::RELU:
        output += RELU;
        output += "\n";
        break;
    case LayerType::LEAKYRELU:
        output += LEAKING_RELU;
        output += "\n";
        break;
    case LayerType::SOFTMAX:
        output += SOFTMAX;
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
