#ifndef LRN_LAYER_PARSER_H_
#define LRN_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LRNType.hpp"

#include <string>

class LRNLayerParser : LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);

private:
    const std::string LRN_TYPE = "type";
    const std::string DEPTH = "depth";
    const LRNType STANDARD_TYPE = LRNType::INTER_CHANNEL;
};
#endif
