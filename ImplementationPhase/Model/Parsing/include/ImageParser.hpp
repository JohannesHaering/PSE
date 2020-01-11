#ifndef IMAGE_PARSER_H_
#define IMAGE_PARSER_H_

#include "Parser.hpp"

#include <string>
#include <list>

class ImageParser : public Parser<Image> {
    public:
        ImageParser(int width, int height, int channelNumb);
        Image parse(std::string toParse);
    protected:
        int width;
        int height;
        int channelNumb;

        virtual std::list<int> resize(std::list<int> rawImage, int width, int height, int channelNumb);
};
#endif