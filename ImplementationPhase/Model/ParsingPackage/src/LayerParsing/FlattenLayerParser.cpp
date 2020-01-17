#include "FlattenLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "FlattenLayer.hpp"
#include "FlattenLayerFactory.hpp"
#include "LayerParserDistribution.hpp"

#include <string>
#include <list>
#include <stdexcept>

NeuralNetworkLayer FlattenLayerParser::parse(std::string toParse)
{
    LayerParser::extractGeneralInformation();
    FlattenLayerFactory factory = FlattenLayerFactory();
    factory.setInputDimensions(LayerParser::inputDimensions);
    factory.setName(LayerParserDistribution::FLATTEN);

    return factory.buildLayer();
}