#include "CollectResultsLayerParser.hpp"
#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "CollectResultLayerFactory.hpp"
#include "CollectResultLayer.hpp"
#include "LayerParserDistribution.hpp"

#include <string>


NeuralNetworkLayer CollectResultsLayerParser::parse(std::string toParse){
    LayerParser::extractGeneralInformation(toParse);
    
    return CollectResultLayerFactory()
        .setName(LayerParserDistribution::COLLECT_RESULTS)
        .setInputDimensions(LayerParser::inputDimensions)
        .buildLayer();
}
