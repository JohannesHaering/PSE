#ifndef LAYER_PARSER_H_
#define LAYER_PARSER_H_

#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"

#include <string>
#include <list>

class LayerParser : public LineBreakParser<NeuralNetworkLayer> {
public:
    NeuralNetworkLayer parse(std::string toParse) override;
private:
    const std::string VALUE_TYPE_DELIMETER = "=";
    const std::string INPUT_DIMENSIONS = "inputdim";
};
#endif