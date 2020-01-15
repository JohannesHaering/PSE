#ifndef POLLING_LAYER_PARSER_H_
#define POLLING_LAYER_PARSER_H_

#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LayerType.hpp"
#include "PollingLayer.hpp"
#include "PoolingLayerFactory.hpp"
#include "PollingType.hpp"

#include <string>

class PollingLayerParser : public LayerParser
{
public:
    NeuralNetworkLayer parse(std::string toParse);

private:
    const std::string SIZE = "size";
    const std::string STRIDE = "stride";
    const std::string POLLINGTYPE = "type";
    const PollingType STANDARD_POLLING_TYPE = PollingType::MAX;
};
#endif