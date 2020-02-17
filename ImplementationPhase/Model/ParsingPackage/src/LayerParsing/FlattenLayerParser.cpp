#include "FlattenLayerParser.hpp"
#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "FlattenLayer.hpp"
#include "FlattenLayerFactory.hpp"
#include "LayerParserDistribution.hpp"

#include <string>
#include <list>
#include <stdexcept>

NetworkLayer* FlattenLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation(toParse);
    FlattenLayerFactory factory = FlattenLayerFactory();
    factory.setInputDimensions(LayerParser::inputDimensions);
    factory.setBatchSize(batchSize);
    factory.setWidth(width);
    factory.setHeight(height);
    factory.setZ(z);

    return factory.buildLayer();
}

std::string FlattenLayerParser::parseBack(NetworkLayer* layer)
{
    std::string output = "";
    output += LayerParser::saveGeneralInformation(layer);

    return output;
}