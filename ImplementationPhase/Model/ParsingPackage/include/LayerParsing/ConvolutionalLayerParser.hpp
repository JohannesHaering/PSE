#ifndef CONVOLUTIONAL_LAYER_PARSER_H_
#define CONVOLUTIONAL_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "ConvolutionalLayer.hpp"
#include "ConvolutionalLayerFactory.hpp"

#include <string>

class ConvolutionalLayerParser : public LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);

private:
    const std::string WEIGHTS_TENSOR = "tensor";
    const std::string STRIDE = "stride";
    const std::string PADDING = "padding";
};
#endif