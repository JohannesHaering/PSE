#ifndef MAXPOOLLAYERPARSER_H_
#define MAXPOOLLAYERPARSER_H_

#include "LayerParser.hpp"
#include <vector>
#include <string>

class MaxPoolLayerParser : public LayerParser
{
public:
    NetworkLayer *parse(std::string toParse) override;
    std::string parseBack(NetworkLayer *layer) override;
};
#endif
