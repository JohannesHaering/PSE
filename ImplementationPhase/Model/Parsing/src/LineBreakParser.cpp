#include "../include/Parser.h"
#include "../include/LineBreakParser.h"
#include <string>
#include <list>

using namespace std;

template <class T>
list<string> LineBreakParser<T>::splitIntoLines(string text) {
    return Parser::splitBySymbol(text, "\n");
}
