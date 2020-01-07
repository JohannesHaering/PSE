#include "../include/LineBreakParser.h"
#include "../include/ImageLocationParser.h"
#include <string>
#include <list>

using namespace std;

template <class T>
list<string> parse(string toParse) {
    auto output = LineBreakParser<T>::splitIntoLines(toParse);
    return output;
}