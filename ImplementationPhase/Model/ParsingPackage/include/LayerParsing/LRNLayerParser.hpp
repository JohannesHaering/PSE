#ifndef LRN_LAYER_PARSER_H_
#define LRN_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "LocalResponseNormalizationLayer.hpp"
#include "LocalResponseNormalizationLayerFactory.hpp"
#include "LRNType.hpp"

#include <string>

class LRNLayerParser : LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(LocalResponseNormalizationLayer layer);

private:
    const std::string LRN_TYPE = "type";
    const std::string DEPTH = "depth";
    const LRNType STANDARD_TYPE = LRNType::INTER_CHANNEL;
};
#endif
