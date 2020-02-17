#include "MaxPoolLayParser.hpp"
#include "LayerParser.hpp"
#include "MaxPoolLayer.hpp"

#include <vector>
#include <string>

NetworkLayer *MaxPoolLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);

    NetworkLayer* layer = new MaxPoolLayer();
    return layer;

std::string MaxPoolLayerParser::parseBack(NetworkLayer *layer)
{
    std::string output = "";
    output += saveGeneralInformation(layer);

    return output;
}