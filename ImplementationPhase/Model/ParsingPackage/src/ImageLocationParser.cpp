#include "LineBreakParser.hpp"
#include "ImageLocationParser.hpp"
#include <string>
#include <list>

std::list<std::string> ImageLocationParser::parse(std::string toParse)
{
    auto output = LineBreakParser::splitIntoLines(toParse);
    return output;
}