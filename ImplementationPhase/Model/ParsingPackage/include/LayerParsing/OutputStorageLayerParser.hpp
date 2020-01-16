#ifndef OUTPUT_STORAGE_LAYER_PARSER_H_
#define OUTPUT_STORAGE_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "OutputStorageLayer.hpp"
#include "OutputStorageLayerFactory.hpp"

#include <string>
#include <vector>

class OutputStorageLayerLayerParser : public LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);

private:
    const std::string OUTPUT_DATA = "outputdata";
};
#endif