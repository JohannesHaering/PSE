#include "ImageParser.hpp"
#include "ImageParserWithSizing.hpp"
#include <opencv2/opencv.hpp>

cv::Mat ImageParserWithSizing::parse(cv::Mat toParse)
{
    cv::Mat output;
    cv::Size size(width, height);
    cv::resize(toParse, output, size);

    return output;
}