#ifndef DENSE_LAYER_PARSER_H_
#define DENSE_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DenseLayer.hpp"
#include "DenseLayerFactory.hpp"

#include <string>
#include <list>

class DenseLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(DenseLayer layer);

private:
    const std::string WEIGHTS_TENSOR = "tensor";
    const std::string BIASES = "bias";
};
#endif