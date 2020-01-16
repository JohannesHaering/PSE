#ifndef COLLECT_RESULT_LAYER_PARSER_H_
#define COLLECT_RESULT_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "CollectResultLayerFactory.hpp"
#include "CollectResultLayer.hpp"

#include <string>

class CollectResultsLayerParser : public LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);
};
#endif