#include "ImageIO.hpp"

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

Data<cv::Mat> ImageIO::readFile(std::string path)
{
    auto image = cv::imread(path, IMREAD_COLOR);
    return Data<cv::Mat>(image);
}