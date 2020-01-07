#ifndef LINE_BREAK_PARSER_H
#define LINE_BREAK_PARSER_H

#include "Parser.h"
#include <string>
#include <list>

using namespace std;

template <class T>
class LineBreakParser : public Parser
{
    protected:
        list<string> splitIntoLines(string text);
};
#endif