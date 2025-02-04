#ifndef IMAGE_PARSER_WITH_SIZING_H_
#define IMAGE_PARSER_WITH_SIZING_H_

#include "ImageParser.hpp"
#include <opencv2/opencv.hpp>

class ImageParserWithSizing : public ImageParser {
public:
	ImageParserWithSizing(int width, int height, int channels);
    cv::Mat parse(cv::Mat toParse);
	std::vector<float> parseFloatsGreyScale(cv::Mat toParse);
};

#endif
