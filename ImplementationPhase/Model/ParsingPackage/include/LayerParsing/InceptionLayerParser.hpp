#ifndef INCEPTION_LAYER_PARSER_H_
#define INCEPTION_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "InceptionLayerFactory.hpp"
#include "InceptionLayer.hpp"

#include <string>

class InceptionLayerParser : public LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);
};
#endif