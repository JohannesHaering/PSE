#include "ImageFileIO.hpp"

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

Data<cv::Mat> ImageFileIO::readFile(std::string path)
{
    auto image = cv::imread(path, cv::IMREAD_COLOR);
    return Data<cv::Mat>(image);
}

bool ImageFileIO::writeFile(Data<cv::Mat> image, std::string path) {
    imwrite(image.getData(), path);
    return true;
}