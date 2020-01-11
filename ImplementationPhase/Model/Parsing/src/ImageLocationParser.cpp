#include "LineBreakParser.hpp"
#include "ImageLocationParser.hpp"
#include <string>
#include <list>

template <class T>
std::list<std::string> parse(std::string toParse)
{
    auto output = LineBreakParser<T>::splitIntoLines(toParse);
    return output;
}