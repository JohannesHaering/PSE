#ifndef IMAGE_PARSER_H
#define IMAGE_PARSER_H

#include "Parser.h"
#include "../../DataStructures/include/Image.h"

#include <string>
#include <list>

using namespace std;

class ImageParser : public Parser<Image> {
    public:
        ImageParser(int width, int height, int channelNumb);
        Image parse(string toParse);
    protected:
        int width;
        int height;
        int channelNumb;

        virtual list<int> resize(list<int> rawImage, int width, int height, int channelNumb);
};
#endif