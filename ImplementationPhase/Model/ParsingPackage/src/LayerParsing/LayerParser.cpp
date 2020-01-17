#include "LayerParser.hpp"
#include "NeuralNetworkLayer.hpp"
#include "LineBreakParser.hpp"
#include "Parser.hpp"

#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <vector>

// Format
// inputDimensions={<int[]>}
// other information
void LayerParser::pextractGeneralInformationarse(std::string toParse)
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
}

std::string LayerParser::extractValuePart(std::string text)
{
    text = removeCharacter(text, VALUE_BEGIN);
    text = removeCharacter(text, VALUE_END);
    return text;
}

int *LayerParser::parseIntArray(std::string text)
{
    std::list<std::string> elements = Parser::splitBySymbol(text, VALUE_PARTS_DELIMETER);
    int *arr = new int[elements.size()];
    int i = 0;
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        arr[i] = ::atoi(*it);
        ++i;
    }
    return arr;
}

std::vector<double> LayerParser::parseFloatVector(std::string text)
{
    std::list<std::string> elements = Parser::splitBySymbol(text, VALUE_PARTS_DELIMETER);
    std::vector<double> vector;
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        vector.push_back(::atof(*it));
    }
    return vector;
}

std::vector<std::vector<double>> parse2DFloatArray(std::string text)
{
    std::vector<std::vector<std::vector<float>>> tensor;
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
                currentArray.append(*charIt);
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
                currentArray.append(*charIt);
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
            if (*charIt == VALUE_PARTS_DELIMETER)
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

std::vector<std::vector<std::vector<float>>> parse3DFloatArray(std::string text)
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
                currentArray.append(*charIt);
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
                currentArray.append(*charIt);
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
            if (*charIt == VALUE_PARTS_DELIMETER)
            {
                ++y
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
