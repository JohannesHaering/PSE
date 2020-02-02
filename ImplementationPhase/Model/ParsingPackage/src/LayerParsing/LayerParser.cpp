#include "LayerParser.hpp"
#include "NetworkLayer.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"
#include "LayerParserDistribution.hpp"

#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cstring>

// Format
// inputDimensions={<int[]>}
// other information
void LayerParser::extractGeneralInformation(std::string toParse)
{
    std::list<std::string> lines = LineBreakParser::splitIntoLines(toParse);
    auto it = lines.begin();
    auto firstLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

    if (*firstLine.begin() != INPUT_DIMENSIONS)
        throw std::invalid_argument("Wrong format");

    auto valuePart = *firstLine.end();

    inputDimensions = parseIntArray(valuePart);
}

std::string LayerParser::removeCharacter(std::string text, char toErase)
{
    text.erase(std::remove(text.begin(), text.end(), toErase), text.end());
	return text;
}

std::string LayerParser::extractValuePart(std::string text)
{
    text = removeCharacter(text, VALUE_BEGIN);
    text = removeCharacter(text, VALUE_END);
    return text;
}

int *LayerParser::parseIntArray(std::string text)
{
    text = removeCharacter(text, VALUE_BEGIN);
    text = removeCharacter(text, VALUE_END);
    std::list<std::string> elements = Parser::splitBySymbol(text, VALUE_PARTS_DELIMETER);
    int *arr = new int[elements.size()];
    int i = 0;
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        std::string value = *it;
        arr[i] = ::atoi(value.c_str());
        ++i;
    }
    return arr;
}

std::vector<float> LayerParser::parseFloatArray(std::string text)
{
    text = removeCharacter(text, VALUE_BEGIN);
    text = removeCharacter(text, VALUE_END);
    std::list<std::string> elements = Parser::splitBySymbol(text, VALUE_PARTS_DELIMETER);
    std::vector<float> vector;
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        std::string value = *it;
        vector.push_back(std::stof(value.c_str()));
    }
    return vector;
}

std::vector<std::vector<float>> LayerParser::parse2DFloatArray(std::string text)
{
    std::vector<std::vector<float>> tensor;
    int x = 0; // in which outerst vector we are
    std::string currentArray = "";
    // 0 -> open bracket, next char can be a [ or a value
    // 1 -> close bracket, next char can be ] or ,
    // 2 -> expects close bracket or ,
    int state = 0;
    int openBrackets = 0;
    for (auto charIt = text.begin(); charIt != text.end(); ++charIt)
    {
        if (state == 0)
        {
            if (*charIt == VALUE_BEGIN)
            {
                ++openBrackets;
            }
            else
            {
                state = 1;
                currentArray.push_back(*charIt);
            }
            continue;
        }
        if (state == 1)
        {
            if (*charIt == VALUE_END)
            {
                tensor.at(x) = parseFloatArray(currentArray);
                currentArray = "";
                --openBrackets;
                state = 2;
            }
            else
            {
                currentArray.push_back(*charIt);
            }
            continue;
        }
        if (state == 2)
        {
            if (*charIt == VALUE_END)
            {
                ++x;
                --openBrackets;
                state = 2;
                continue;
            }
            if (std::string(1, *charIt) == VALUE_PARTS_DELIMETER)
            {
                state = 0;
                continue;
            }

            throw std::invalid_argument("Wrong format");
        }
    }

    if (openBrackets != 0)
    {
        throw std::invalid_argument("Wrong format");
    }

    return tensor;
}

std::vector<std::vector<std::vector<float>>> LayerParser::parse3DFloatArray(std::string text)
{
    std::vector<std::vector<std::vector<float>>> tensor;
    int x = 0; // in which outerst vector we are
    int y = 0; // in which middle vector we are
    std::string currentArray = "";
    // 0 -> open bracket, next char can be a [ or a value
    // 1 -> close bracket, next char can be ] or ,
    // 2 -> expects close bracket or ,
    int state = 0;
    int openBrackets = 0;
    for (auto charIt = text.begin(); charIt != text.end(); ++charIt)
    {
        if (state == 0)
        {
            if (*charIt == VALUE_BEGIN)
            {
                ++openBrackets;
            }
            else
            {
                state = 1;
                currentArray.push_back(*charIt);
            }
            continue;
        }
        if (state == 1)
        {
            if (*charIt == VALUE_END)
            {
                tensor.at(x).at(y) = parseFloatArray(currentArray);
                currentArray = "";
                --openBrackets;
                state = 2;
            }
            else
            {
                currentArray.push_back(*charIt);
            }
            continue;
        }
        if (state == 2)
        {
            if (*charIt == VALUE_END)
            {
                ++x;
                y = 0;
                --openBrackets;
                state = 2;
                continue;
            }
            if (std::string(1, *charIt) == VALUE_PARTS_DELIMETER)
            {
                ++y;
                state = 0;
                continue;
            }

            throw std::invalid_argument("Wrong format");
        }
    }

    if (openBrackets != 0)
    {
        throw std::invalid_argument("Wrong format");
    }

    return tensor;
}

std::vector<std::vector<std::vector<std::vector<float>>>> LayerParser::parse4DFloatArray(std::string text)
{
    std::vector<std::vector<std::vector<std::vector<float>>>> tensor;
    std::string currentArray = "";

    auto it = text.begin();
    int i = 0;
    ++it;
    for (; it != text.end(); ++it)
    {
        currentArray += *it;
        if (*it == VALUE_END)
        {
            ++it;
            if (*it == VALUE_END)
            {
                ++it;
                if (*it == VALUE_END)
                {
                    ++it;
                    currentArray += "]]]";
                    tensor.at(i) = parse3DFloatArray(currentArray);
                    ++i;
                }
                else
                {
                    --it;
                    --it;
                }
            }
            else
            {
                --it;
            }
        }
    }

    return tensor;
}

std::string LayerParser::saveGeneralInformation(NetworkLayer layer)
{
    std::string output = "";
    output += LayerParser::VALUE_BEGIN;
    switch (layer.getLayerType())
    {
    case LayerType::ACTIVATION:
        output += LayerParserDistribution().ACTIVATION;
        break;
    case LayerType::COLLECT_RESULTS:
        output += LayerParserDistribution().COLLECT_RESULTS;
        break;
    case LayerType::CONVOLUTION:
        output += LayerParserDistribution().CONVOLUTIONAL;
        break;
    case LayerType::DENSE:
        output += LayerParserDistribution().DENSE;
        break;
    case LayerType::DROPOUT:
        output += LayerParserDistribution().DROPOUT;
        break;
    case LayerType::FLATTEN:
        output += LayerParserDistribution().FLATTEN;
        break;
    case LayerType::INCEPTION:
        output += LayerParserDistribution().INCEPTION;
        break;
    case LayerType::LRN:
        output += LayerParserDistribution().LOCAL_RESPONSE_NORMALIZATION;
        break;
    case LayerType::OUTPUT_STORAGE:
        output += LayerParserDistribution().OUTPUT_STORAGE;
        break;
    case LayerType::POLLING:
        output += LayerParserDistribution().POLLING;
        break;
    }
    output += LayerParser::VALUE_END;
    output += INPUT_DIMENSIONS + VALUE_TYPE_DELIMETER;
    output += saveIntArray(layer.getInputDimensions());
    output += "\n";
	return output;
}

std::string LayerParser::saveIntArray(int *arr)
{
    std::string output = std::to_string(VALUE_BEGIN);
    output += std::to_string(*arr);
    for (auto it = ++arr; it != nullptr; ++it)
    {
        output += VALUE_PARTS_DELIMETER;
        output += std::to_string(*arr);
    }
    output += std::to_string(VALUE_END);

    return output;
}

std::string LayerParser::saveFloatArray(std::vector<float> arr)
{
    std::string output = std::to_string(VALUE_BEGIN);
    output += std::to_string(arr.at(0));
    for (int i = 1; i < arr.size(); ++i)
    {
        output += VALUE_PARTS_DELIMETER;
        output += std::to_string(arr.at(i));
    }
    output += std::to_string(VALUE_END);

    return output;
}

std::string LayerParser::save2DFloatArray(std::vector<std::vector<float>> arr)
{
    std::string output = std::to_string(VALUE_BEGIN);
    output += saveFloatArray(arr.at(0));
    for (int i = 1; i < arr.size(); ++i)
    {
        output += VALUE_PARTS_DELIMETER;
        output += saveFloatArray(arr.at(0));
    }
    output += std::to_string(VALUE_END);

    return output;
}

std::string LayerParser::save3DFloatArray(std::vector<std::vector<std::vector<float>>> arr)
{
    std::string output = std::to_string(VALUE_BEGIN);
    output += save2DFloatArray(arr.at(0));
    for (int i = 1; i < arr.size(); ++i)
    {
        output += VALUE_PARTS_DELIMETER;
        output += save2DFloatArray(arr.at(0));
    }
    output += std::to_string(VALUE_END);

    return output;
}

std::string LayerParser::save4DFloatArray(std::vector<std::vector<std::vector<std::vector<float>>>> arr)
{
    std::string output = std::to_string(VALUE_BEGIN);
    output += save3DFloatArray(arr.at(0));
    for (int i = 1; i < arr.size(); ++i)
    {
        output += VALUE_PARTS_DELIMETER;
        output += save3DFloatArray(arr.at(0));
    }
    output += std::to_string(VALUE_END);

    return output;
}
