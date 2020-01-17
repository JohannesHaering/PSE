#ifndef NEURAL_NETWORK_PARSER_H_
#define NEURAL_NETWORK_PARSER_H_

#include "LineBreakParser.hpp"
#include "NeuralNetwork.hpp"

#include <string>

class NeuralNetworkParser : public LineBreakParser<NeuralNetwork>
{
public:
    NeuralNetwork parse(std::string toParse);

private:
    const std::string TYPE_BEGIN = "[";
};
#endif