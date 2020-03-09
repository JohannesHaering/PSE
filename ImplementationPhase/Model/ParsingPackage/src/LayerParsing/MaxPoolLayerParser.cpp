#include "MaxPoolLayerParser.hpp"
#include "LayerParser.hpp"
#include "MaxPoolLayer.hpp"

#include <vector>
#include <string>

NetworkLayer *MaxPoolLayerParser::parse(std::string toParse)
{
    NetworkLayer* layer = new MaxPoolLayer();
    return layer;
}

std::string MaxPoolLayerParser::parseBack(NetworkLayer *layer)
{
    std::string output = "[maxpool]";
    output += "\n";
    return output;
}
