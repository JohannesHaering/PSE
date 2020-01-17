#include "NeuralNetworkParser.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"
#include "NeuralNetwork.hpp"
#include "LayerParserDistribution.hpp"
#include "NeuralNetworkFactory.hpp"
#include "NeuralNetworkLayer.hpp"

#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>

NeuralNetwork NeuralNetworkParser::parse(std::string toParse)
{
    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    auto firtstLine = *it;
    auto name = removeCharacter(removeCharacter(firtstLine, TYPE_BEGIN), TYPE_END);

    NeuralNetworkFactory factory = NeuralNetworkFactory();
    factory.setName(name);

    ++it;

    auto parts1It = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER).begin;
    if (*parts1It != HEIGHT)
        throw std::invalid_argument("Wrong format");
    ++parts1It;
    factory.setHeight(::atoi(*parts1It));
    ++it;

    auto parts2It = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER).begin;
    if (*parts2It != WIDTH)
        throw std::invalid_argument("Wrong format");
    ++parts2It;
    factory.setWidth(::atoi(*parts2It));
    ++it;

    auto parts3It = Parser::splitBySymbol(*it, VALUE_PART_DELIMETER).begin;
    if (*parts3It != CHANNELS)
        throw std::invalid_argument("Wrong format");
    ++parts3It;
    factory.setChannels(::atoi(*parts3It));

    ++it;

    // Here the layer configurations are comming
    std::list<NeuralNetworkLayer> layers;
    std::string currentLayerBlock = "";
    // 0 -> adding lines
    int currentState = 0;
    for (; it != lines.end(); ++it)
    {
        if(*(*it).begin() == TYPE_BEGIN){
            LayerParserDistribution().parse(currentLayerBlock);
            currentLayerBlock = "";
        }

        currentLayerBlock.append(*it);
        currentLayerBlock.append("\n"); // because the line breaks were erased when the string was split
    }

    factory.setLayers(layers);

    return factory.buildNeuralNetwork();
}

std::string NeuralNetworkParser::removeCharacter(std::string text, char toErase)
{
    text.erase(std::remove(text.begin(), text.end(), toErase), text.end());
}