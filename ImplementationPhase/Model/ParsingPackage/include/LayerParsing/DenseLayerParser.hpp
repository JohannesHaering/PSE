#ifndef DENSE_LAYER_PARSER_H_
#define DENSE_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"

#include <string>
#include <list>

class DenseLayerParser : public LayerParser {
    public:
        NeuralNetworkLayer parse(std::string toParse);
    private:
        const std::string PADDING = "padding";
        const std::string STRIDE = "stride";
        const std::string WEIGHTS_TENSOR = "weights_tensor";
};
#endif