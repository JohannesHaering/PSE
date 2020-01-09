#ifndef IMAGE_PARSER_WITH_PADDING
#define IMAGE_PARSER_WITH_PADDING

#include "ImageParser.h"
#include "Image.h"

#include <string>
#include <list>

using namespace std;
class ImageParserWithCropping : public ImageParser {
    private:
        int paddingColor;
};

#endif