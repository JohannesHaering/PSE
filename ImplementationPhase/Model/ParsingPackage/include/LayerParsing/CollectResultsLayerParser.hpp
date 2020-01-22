#ifndef COLLECT_RESULT_LAYER_PARSER_H_
#define COLLECT_RESULT_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "CollectResultsLayerFactory.hpp"
#include "CollectResultsLayer.hpp"

#include <string>

class CollectResultsLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(CollectResultsLayer layer);
};
#endif