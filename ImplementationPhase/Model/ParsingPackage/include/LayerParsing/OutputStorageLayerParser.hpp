#ifndef OUTPUT_STORAGE_LAYER_PARSER_H_
#define OUTPUT_STORAGE_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "OutputStorageLayer.hpp"
#include "OutputStorageLayerFactory.hpp"

#include <string>
#include <vector>

class OutputStorageLayerParser : public LayerParser
{
public:
    NetworkLayer parse(std::string toParse) override;
    std::string parseBack(OutputStorageLayer layer);

private:
    const std::string OUTPUT_DATA = "outputdata";
};
#endif