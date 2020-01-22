#ifndef CONVOLUTIONAL_LAYER_PARSER_H_
#define CONVOLUTIONAL_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionLayer.hpp"
#include "ConvolutionalLayerFactory.hpp"

#include <string>

class ConvolutionalLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(ConvolutionLayer layer);

private:
    const std::string WEIGHTS_TENSOR = "tensor";
    const std::string STRIDE = "stride";
    const std::string PADDING = "padding";
};
#endif