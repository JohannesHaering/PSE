#ifndef IMAGE_IO_H_
#define IMAGE_IO_H_

#include "Data.hpp"
#include "FileIO.hpp"

#include <string>
#include <opencv2/opencv.hpp>

class ImageFileIO : public FileIO {
    public:
        Data<cv::Mat> readFile(std::string path);
        bool writeFile(Data<cv::Mat image>, std::string path);
};
#endif
