#include "Parser.hpp"
#include <string>
#include <list>

template <class T>
std::list<std::string> Parser<T>::splitBySymbol(std::string text, std::string symbol)
{
    std::list<std::string> output;
    size_t pos = 0;
    string token;
    while ((pos = s.find(symbol)) != std::string::npos)
    {
        token = s.substr(0, pos);
        output.push_back(token);
        s.erase(0, pos + symbol.length());
    }
}