#ifndef LAYER_PARSER_H_
#define LAYER_PARSER_H_

#include "NetworkLayer.hpp"
#include "LineBreakParser.hpp"
#include "LayerType.hpp"

#include <string>
#include <list>
#include <vector>

class LayerParser : public LineBreakParser<NetworkLayer>
{
public:
    virtual NetworkLayer parse(std::string toParse) = 0;

protected:
    std::string removeCharacter(std::string text, char toErase);
    std::string extractValuePart(std::string text);
    int *parseIntArray(std::string text);
    std::vector<float> parseFloatArray(std::string text);
    void extractGeneralInformation(std::string text);
    std::vector<std::vector<float>> parse2DFloatArray(std::string text);
    std::vector<std::vector<std::vector<float>>> parse3DFloatArray(std::string text);
    std::vector<std::vector<std::vector<std::vector<float>>>> parse4DFloatArray(std::string text);
    std::string saveGeneralInformation(NetworkLayer layer);
    std::string saveIntArray(int* arr);
    std::string saveFloatArray(std::vector<float> arr);
    std::string save2DFloatArray(std::vector<std::vector<float>> arr);
    std::string save3DFloatArray(std::vector<std::vector<std::vector<float>>> arr);
    std::string save4DFloatArray(std::vector<std::vector<std::vector<std::vector<float>>>> arr);
    const std::string VALUE_TYPE_DELIMETER = "=";
    const std::string INPUT_DIMENSIONS = "inputdim";
    const std::string VALUE_PARTS_DELIMETER = ",";
    const char VALUE_BEGIN = '[';
    const char VALUE_END = ']';
    int *inputDimensions;
};
#endif
