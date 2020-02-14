#ifndef POLLING_LAYER_PARSER_H_
#define POLLING_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LayerType.hpp"
#include "PollingLayer.hpp"
#include "PollingLayerFactory.hpp"
#include "PollingType.hpp"

#include <string>

class PollingLayerParser : public LayerParser
{
public:
    NetworkLayer* parse(std::string toParse) override;
    std::string parseBack(PollingLayer* layer);

private:
    const std::string SIZE = "size";
    const std::string STRIDE = "stride";
    const std::string POLLING_TYPE = "type";
    PollingType STANDARD_POLLING_TYPE = PollingType::MAX;
};
#endif