#include "FileIO.hpp"
#include "Data.hpp"
#include "VideoFileIO.hpp"

#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>

Data<cv::VideoCapture> VideoFileIO::readFile(std::string path)
{
    cv::VideoCapture video(path);
    return Data<cv::VideoCapture>(video);
}