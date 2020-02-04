#ifndef NEURAL_NETWORK_PARSER_H_
#define NEURAL_NETWORK_PARSER_H_

#include "LineBreakParser.hpp"
#include "NeuralNetwork.hpp"

#include <string>

class NeuralNetworkParser : public LineBreakParser<NeuralNetwork>
{
public:
    NeuralNetwork parse(std::string toParse);
    std::string parseBack(NeuralNetwork NeuralNetwork);

private:
    const char TYPE_BEGIN = '[';
    const char TYPE_END = ']';
    const std::string VALUE_PART_DELIMETER = "=";
    const std::string HEIGHT = "height";
    const std::string WIDTH = "width";
    const std::string CHANNELS = "channels";

    std::string removeCharacter(std::string text, char toErase);
};
#endif