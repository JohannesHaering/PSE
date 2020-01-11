#ifndef MULTIPLE_IMAGE_IO_H_
#define MULTIPLE_IMAGE_IO_H_

#include "Data.hpp"
#include "ImageIO.hpp"

#include <string>
#include <list>
#include <opencv2/opencv.hpp>

class MultipleImageIO : public ImageFileIO {
    public:
        Data<std::list<cv::Mat>> readFile(std::list<std::string> paths);
        bool writeFile(Data<std::list<cv::Mat image>>, std::list<std::string> paths);
};
#endif