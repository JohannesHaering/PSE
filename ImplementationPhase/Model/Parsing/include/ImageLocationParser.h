#ifndef IMAGE_LOCATION_PARSER_H
#define IMAGE_LOCATION_PARSER_H

#include "LineBreakParser.h"
#include <string>
#include <list>

using namespace std;

class ImageLocationParser : public LineBreakParser<list<string>>
{
    public:
        list<string> parse(string toParse);
};
#endif