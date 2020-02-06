#include "ImageParser.hpp"
#include "ImageParserWithSizing.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

ImageParserWithSizing::ImageParserWithSizing(int width, int height, int channels) :  ImageParser(width, height, channels) {};

cv::Mat ImageParserWithSizing::parse(cv::Mat toParse)
{
    cv::Mat output;
    cv::Size size(width, height);
    cv::resize(toParse, output, size);

    return output;
}

std::vector<float> ImageParserWithSizing::parseFloatsGreyScale(cv::Mat toParse) {
    std::vector<float> output = std::vector<float>();
    cv::Mat temp;
    cv::Size size(width, height);
    cv::resize(toParse, temp, size);

    for (int i = 0; i < temp.total(); i++) {
        output.push_back(((float)temp.data[i]) / 255.0f);
    }
    return output;
}
