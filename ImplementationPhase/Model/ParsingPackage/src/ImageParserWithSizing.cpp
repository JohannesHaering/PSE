#include "ImageParser.hpp"
#include "ImageParserWithSizing.hpp"
#include <opencv2/opencv.hpp>

ImageParserWithSizing::ImageParserWithSizing(int width, int height, int channels) :  ImageParser(width, height, channels) {};

cv::Mat ImageParserWithSizing::parse(cv::Mat toParse)
{
    cv::Mat output;
    cv::Size size(width, height);
    cv::resize(toParse, output, size);

    return output;
}
