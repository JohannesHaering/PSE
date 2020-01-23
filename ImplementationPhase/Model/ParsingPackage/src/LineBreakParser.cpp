#include "Parser.hpp"
#include "LineBreakParser.hpp"
#include <string>
#include <list>

template <class T>
std::list<std::string> LineBreakParser<T>::splitIntoLines(std::string text) {
    return Parser<T>::splitBySymbol(text, "\n");
}

