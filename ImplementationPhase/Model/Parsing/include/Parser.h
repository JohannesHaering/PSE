#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <list>

using namespace std;

template <class T>
class Parser {
    public:
        Parser() {

        }
        virtual T parse(string toParse);
    protected:
        list<string> splitBySymbol(string text, string symbol);
};
#endif