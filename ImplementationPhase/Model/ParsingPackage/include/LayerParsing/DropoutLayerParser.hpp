#ifndef DROPOUT_LAYER_PARSER_H_
#define DROPOUT_LAYER_PARSER_H

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "DropoutLayer.hpp"
#include "DropoutLayerFactory.hpp"

#include <string>

class DropoutLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(DropoutLayer layer);

private:
    const std::string DROPOUT_RATE = "rate";
    const float STANDARD_RATE = 0.1f;
};
#endif