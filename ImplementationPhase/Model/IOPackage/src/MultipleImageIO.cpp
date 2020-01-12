#include "ImageFileIO.hpp"
#include "MultipleImageFileIO.hpp"
#include "Data.hpp"

#include <string>
#include <list>
#include <iostream>
#include <opencv2/opencv.hpp>

Data<std::list<cv::Mat>> MultipleImageFileIO::readFile(std::list<std::string> paths)
{
    std::list<cv::Mat> images;
    for (auto it = paths.begin(); it != paths.end(); ++it)
    {
        images.push_back(ImageFileIO::readFile(*it));
    }
    return Data<std::list<cv::Mat>>(images);
}