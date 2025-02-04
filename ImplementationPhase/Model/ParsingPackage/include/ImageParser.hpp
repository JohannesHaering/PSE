#ifndef IMAGE_PARSER_H_
#define IMAGE_PARSER_H_

#include "Parser.hpp"
#include <opencv2/opencv.hpp>

#include <string>
#include <list>

class ImageParser : public Parser<cv::Mat> {
    public:
		ImageParser();
        ImageParser(int width, int height, int channelNumb);
        cv::Mat parse(cv::Mat toParse);
    protected:
        int width;
        int height;
        int channelNumb;
};
#endif
