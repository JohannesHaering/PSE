#ifndef FLATTEN_LAYER_PARSER_H_
#define FLATTEN_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp" 
#include "FlattenLayer.hpp"
#include "FlattenLayerFactory.hpp"

#include <string>

class FlattenLayerParser : public LayerParser {
    public:
    NeuralNetworkLayer parse (std::string toParse);
    private:
    const std::string matrix = "matrix";
};
#endif