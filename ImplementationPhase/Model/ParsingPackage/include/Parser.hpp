#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <list>

template <class T>
class Parser
{
public:
    Parser()
    {
    }
    virtual T parse(std::string toParse);
    static std::list<std::string> splitBySymbol(std::string text, std::string symbol);
};
#endif
