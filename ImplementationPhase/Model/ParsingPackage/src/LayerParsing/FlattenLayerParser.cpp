#include "FlattenLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "FlattenLayer.hpp"
#include "FlattenLayerFactory.hpp"
#include "LayerParserDistribution.hpp"
#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

NetworkLayer* FlattenLayerParser::parse(std::string toParse)
{
    FlattenLayerFactory factory = FlattenLayerFactory();
    return factory.buildLayer();
}

std::string FlattenLayerParser::parseBack(NetworkLayer* layer)
{
    std::string output = "[flatten]\n";

    return output;
}
