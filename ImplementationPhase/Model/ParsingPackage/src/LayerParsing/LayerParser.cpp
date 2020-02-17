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
	std::list<std::string>::iterator it = lines.begin();
	std::list<std::string> firstLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

	++it;
	std::list<std::string> secondLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

	if (!(*secondLine.begin()).compare(BATCH_SIZE))
		throw std::invalid_argument("Wrong format");

	std::string batchSizeString = *(--secondLine.end());
	batchSize = ::atoi(batchSizeString.c_str());

	++it;
	std::list<std::string> thirdLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

	if (!(*thirdLine.begin()).compare(WIDTH))
		throw std::invalid_argument("Wrong format");

	std::string widthString = *(--thirdLine.end());
	width = ::atoi(widthString.c_str());

	++it;
	std::list<std::string> fourthLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

	if (!(*fourthLine.begin()).compare(HEIGHT))
		throw std::invalid_argument("Wrong format");

	std::string heightString = *(--fourthLine.end());
	height = ::atoi(heightString.c_str());

	++it;
	std::list<std::string> fithLine = Parser::splitBySymbol(*it, VALUE_TYPE_DELIMETER);

	if (!(*fithLine.begin()).compare(Z))
		throw std::invalid_argument("Wrong format");

	std::string zString = *(--fithLine.end());
	z = ::atoi(zString.c_str());

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

int* LayerParser::parseIntArray(std::string text)
{
	text = removeCharacter(text, VALUE_BEGIN);
	text = removeCharacter(text, VALUE_END);
	std::list<std::string> elements = Parser::splitBySymbol(text, VALUE_PARTS_DELIMETER);
	int* arr = new int[elements.size()];
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
	std::vector<std::vector<float>> tensor = std::vector<std::vector<float>>();
	int x = 0; // in which outerst vector we are
	std::string currentArray = "";
	// 0 -> open bracket, next char can be a [ or a value
	// 1 -> close bracket, next char can be ] or ,
	// 2 -> expects close bracket or ,
	int state = 0;
	int openBrackets = 0;
	for (auto charIt = ++text.begin(); charIt != text.end(); ++charIt)
	{
		currentArray += *charIt;
		if (state == 0)
		{
			if (*charIt == VALUE_BEGIN)
			{
				++openBrackets;
			}
			else
			{
				state = 1;
			}
			continue;
		}
		if (state == 1)
		{
			if (*charIt == VALUE_END)
			{
				tensor.push_back(parseFloatArray(currentArray));
				currentArray = "";
				--openBrackets;
				state = 2;
			}
			else
			{
				currentArray += (*charIt);
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
	return tensor;
}

std::vector<std::vector<std::vector<float>>> LayerParser::parse3DFloatArray(std::string text)
{
	std::vector<std::vector<std::vector<float>>> tensor = std::vector<std::vector<std::vector<float>>>();
	int x = 0; // in which outerst vector we are
	int y = 0; // in which middle vector we are
	std::string currentArray = "";
	// 0 -> open bracket, next char can be a [ or a value
	// 1 -> close bracket, next char can be ] or ,
	// 2 -> expects close bracket or ,
	int state = 0;
	int i = 0;
	int openBrackets = 0;
	for (auto it = ++text.begin(); it != text.end(); ++it)
	{
		currentArray += *it;
		if (*it == VALUE_END)
		{
			++it;
			if (it == text.end())
				break;
			currentArray += *it;
			if (*it == VALUE_END)
			{
				tensor.push_back(parse2DFloatArray(currentArray));
				++i;
			}
		}
	}
	return tensor;
}

std::vector<std::vector<std::vector<std::vector<float>>>> LayerParser::parse4DFloatArray(std::string text)
{
	std::vector<std::vector<std::vector<std::vector<float>>>> tensor = std::vector<std::vector<std::vector<std::vector<float>>>>();
	auto sub1 = std::vector<std::vector<std::vector<float>>>();
	auto sub2 = std::vector<std::vector<float>>();
	auto sub3 = std::vector<float>();


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
			if (it == text.end())
				break;
			currentArray += *it;
			if (*it == VALUE_END)
			{
				++it;
				if (it == text.end())
					break;
				currentArray += *it;
				if (*it == VALUE_END)
				{
					tensor.push_back(parse3DFloatArray(currentArray));
					++i;
				}
			}
		}
	}

	return tensor;
}

std::string LayerParser::saveGeneralInformation(NetworkLayer* layer)
{
	std::string output = "";
	output += LayerParser::VALUE_BEGIN;
	switch (layer->getLayerType())
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
	output += "\n";
	output += "\n";
	output += BATCH_SIZE;
	output += VALUE_TYPE_DELIMETER;
	output += std::to_string(layer->getBatchSize());
	output += "\n";
	output += WIDTH;
	output += VALUE_TYPE_DELIMETER;
	output += std::to_string(layer->getWidth());
	output += "\n";
	output += HEIGHT;
	output += VALUE_TYPE_DELIMETER;
	output += std::to_string(layer->getHeight());
	output += "\n";
	output += Z;
	output += VALUE_TYPE_DELIMETER;
	output += std::to_string(layer->getZ());
	output += "\n";

	return output;
}

std::string LayerParser::saveIntArray(int* arr)
{
	std::string output = "";
	output += VALUE_BEGIN;
	output += std::to_string(*arr);
	for (int i = 1; i <= sizeof(arr) / sizeof(arr[0]); i++)
	{
		output += VALUE_PARTS_DELIMETER;
		output += std::to_string(arr[i]);
	}
	output += VALUE_END;

	return output;
}

std::string LayerParser::saveFloatArray(std::vector<float> arr)
{
	std::string output = "";
	output += (VALUE_BEGIN);
	output += std::to_string(arr.at(0));
	for (int i = 1; i < arr.size(); ++i)
	{
		output += VALUE_PARTS_DELIMETER;
		output += std::to_string(arr.at(i));
	}
	output += (VALUE_END);

	return output;
}

std::string LayerParser::save2DFloatArray(std::vector<std::vector<float>> arr)
{
	std::string output = "";
	output += (VALUE_BEGIN);
	output += saveFloatArray(arr.at(0));
	for (int i = 1; i < arr.size(); ++i)
	{
		output += VALUE_PARTS_DELIMETER;
		output += saveFloatArray(arr.at(0));
	}
	output += (VALUE_END);

	return output;
}

std::string LayerParser::save3DFloatArray(std::vector<std::vector<std::vector<float>>> arr)
{
	std::string output = "";
	output += (VALUE_BEGIN);
	output += save2DFloatArray(arr.at(0));
	for (int i = 1; i < arr.size(); ++i)
	{
		output += VALUE_PARTS_DELIMETER;
		output += save2DFloatArray(arr.at(0));
	}
	output += (VALUE_END);

	return output;
}

std::string LayerParser::save4DFloatArray(std::vector<std::vector<std::vector<std::vector<float>>>> arr)
{
	std::string output = "";
	output += (VALUE_BEGIN);
	output += save3DFloatArray(arr.at(0));
	for (int i = 1; i < arr.size(); ++i)
	{
		output += VALUE_PARTS_DELIMETER;
		output += save3DFloatArray(arr.at(0));
	}
	output += (VALUE_END);

	return output;
}
