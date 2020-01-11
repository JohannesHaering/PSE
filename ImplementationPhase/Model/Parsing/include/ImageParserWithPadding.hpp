#ifndef IMAGE_PARSER_WITH_PADDING_H_
#define IMAGE_PARSER_WITH_PADDING_H_

#include "ImageParser.hpp"
class ImageParserWithCropping : public ImageParser {
    private:
        int paddingColor;
};

#endif