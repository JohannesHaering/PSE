#include "../include/Parser.h"
#include <string>
#include <list>

using namespace std;

template <class T>
list<string> Parser<T>::splitBySymbol(string text, string symbol) {
    list<string> output;
    size_t pos = 0;
    string token;
    while ((pos = s.find(symbol)) != string::npos) {
        token = s.substr(0, pos);
        output.push_back(token);
        s.erase(0, pos + symbol.length());
    }
}