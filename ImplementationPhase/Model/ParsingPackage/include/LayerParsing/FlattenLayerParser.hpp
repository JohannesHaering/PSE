#ifndef FLATTEN_LAYER_PARSER_H_
#define FLATTEN_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "FlattenLayer.hpp"
#include "FlattenLayerFactory.hpp"

#include <string>

class FlattenLayerParser : public LayerParser
{
public:
    NetworkLayer* parse(std::string toParse) override;
    std::string parseBack(FlattenLayer* layer);
};
#endif