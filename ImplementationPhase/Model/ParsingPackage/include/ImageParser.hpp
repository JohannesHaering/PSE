#ifndef IMAGE_PARSER_H_
#define IMAGE_PARSER_H_

#include "Parser.hpp"
#include <opencv2/opencv.hpp>

#include <string>
#include <list>

class ImageParser : public Parser<cv::Mat> {
    public:
        ImageParser(int width, int height, int channelNumb);
        virtual cv::Mat parse(std::string toParse);
    protected:
        int width;
        int height;
        int channelNumb;
};
#endif
