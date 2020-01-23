#ifndef IMAGE_LOCATION_PARSER_H_
#define IMAGE_LOCATION_PARSER_H_

#include "LineBreakParser.hpp"
#include <string>
#include <list>

class ImageLocationParser : public LineBreakParser<std::list<std::string>>
{
    public:
        std::list<std::string> parse(std::string toParse) override;
};
#endif