#ifndef LINE_BREAK_PARSER_H_
#define LINE_BREAK_PARSER_H_

#include "Parser.hpp"
#include <string>
#include <list>
template <class T>
class LineBreakParser : public Parser<T>
{
  public:
    static std::list<std::string> splitIntoLines(std::string text) {
        return Parser<T>::splitBySymbol(text, "\n");
    }

};
#endif
