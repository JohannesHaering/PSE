#ifndef VIDEO_IO_H_
#define VIDEO_IO_H_

#include "FileIO.hpp"
#include "Data.hpp"

#include <string>
#include <opencv2/opencv.hpp>

class VideoIO : public FileIO
{
public:
    Data<cv::VideoCapture> readFile(std::string path);
}:
#endif