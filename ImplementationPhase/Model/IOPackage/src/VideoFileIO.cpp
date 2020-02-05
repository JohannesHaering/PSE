#include "FileIO.hpp"
#include "Data.hpp"
#include "VideoFileIO.hpp"

#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>

Data<cv::VideoCapture> VideoFileIO::readFile(std::string path)
{
    int length = path.length();
    if (path[length - 1] == 'i' && path[length - 2] == 'v' && path[length - 3] == 'a' && path[length - 4] == '.')
    {
	cv::VideoCapture videoCapture;
        return Data<cv::VideoCapture>(videoCapture);
    }
    cv::VideoCapture video(path);
    return Data<cv::VideoCapture>(video);
}
