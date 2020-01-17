#ifndef LAYER_PARSER_H_
#define LAYER_PARSER_H_

#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"
#include "LayerType.hpp"

#include <string>
#include <list>
#include <vector>

class LayerParser : public LineBreakParser<NeuralNetworkLayer>
{
public:
    virtual NeuralNetworkLayer parse(std::string toParse);

protected:
    std::string removeCharacter(std::string text, char toErase);
    std::string extractValuePart(std::string text);
    int *parseIntArray(std::string text);
    std::vector<double> parseFloatArray(std::string text);
    void extractGeneralInformation(std::string text);
    std::vector<std::vector<double>> parse2DFloatArray(std::string text);
    std::vector<std::vector<std::vector<float>>> parse3DFloatArray(std::string text);
    const std::string VALUE_TYPE_DELIMETER = "=";
    const std::string INPUT_DIMENSIONS = "inputdim";
    const std::string VALUE_PARTS_DELIMETER = ",";
    int *inputDimensions;
};
#endif