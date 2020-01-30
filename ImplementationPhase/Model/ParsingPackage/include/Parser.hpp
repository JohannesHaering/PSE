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
    virtual T parse(std::string toParse) {

    }
    static std::list<std::string> splitBySymbol(std::string text, std::string symbol)
    {
        std::list<std::string> output;
        size_t pos = 0;
        std::string token;
        while ((pos = text.find(symbol)) != std::string::npos)
        {
            token = text.substr(0, pos);
            output.push_back(token);
            text.erase(0, pos + symbol.length());
        }
        return output;
    }
};
#endif
