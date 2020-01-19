#ifndef INCEPTION_LAYER_PARSER_H_
#define INCEPTION_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"

#include <string>

class InceptionLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(InceptionLayer layer);
};
#endif